#include <bits/stdc++.h>
using namespace std;
//gen by AI
class Player;

// ===================== CARD =====================
class Card {
private:
    int rank;          // 2..14 (11:J, 12:Q, 13:K, 14:A)
    string suit;       // Hearts, Diamonds, Clubs, Spades
    bool faceUp;

public:
    Card(int rank = 2, string suit = "Hearts", bool faceUp = true) {
        this->rank = rank;
        this->suit = suit;
        this->faceUp = faceUp;
    }

    int getRank() const {
        return rank;
    }

    string getSuit() const {
        return suit;
    }

    void flip() {
        faceUp = !faceUp;
    }

    int compareTo(const Card& other) const {
        if (rank > other.rank) return 1;
        if (rank < other.rank) return -1;
        return 0;
    }

    string rankToString() const {
        if (rank >= 2 && rank <= 10) return to_string(rank);
        if (rank == 11) return "J";
        if (rank == 12) return "Q";
        if (rank == 13) return "K";
        return "A";
    }

    string toString() const {
        if (!faceUp) return "[Hidden]";
        return rankToString() + " of " + suit;
    }
};

// ===================== HAND =====================
class Hand {
private:
    vector<Card> cards;
    int value;   // dùng để so bài

public:
    Hand() {
        value = 0;
    }

    void clear() {
        cards.clear();
        value = 0;
    }

    void addCard(const Card& c) {
        if (cards.size() < 2) {
            cards.push_back(c);
            evaluate();
        }
    }

    const vector<Card>& getCards() const {
        return cards;
    }

    bool isPair() const {
        return cards.size() == 2 && cards[0].getRank() == cards[1].getRank();
    }

    void evaluate() {
        if (cards.size() < 2) {
            value = 0;
            return;
        }

        int r1 = cards[0].getRank();
        int r2 = cards[1].getRank();

        if (r1 == r2) {
            value = 1000 + r1; // đôi luôn mạnh hơn bài thường
        } else {
            int high = max(r1, r2);
            int low = min(r1, r2);
            value = high * 20 + low;
        }
    }

    int compareTo(const Hand& other) const {
        if (value > other.value) return 1;
        if (value < other.value) return -1;
        return 0;
    }

    string toString() const {
        if (cards.empty()) return "No cards";
        string s = "";
        for (int i = 0; i < (int)cards.size(); i++) {
            s += cards[i].toString();
            if (i != (int)cards.size() - 1) s += ", ";
        }
        return s;
    }
};

// ===================== DECK =====================
class Deck {
private:
    vector<Card> cards;
    int topIndex;

public:
    Deck() {
        reset();
    }

    void reset() {
        cards.clear();
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

        for (int i = 0; i < 4; i++) {
            for (int rank = 2; rank <= 14; rank++) {
                cards.push_back(Card(rank, suits[i], true));
            }
        }

        topIndex = 0;
    }

    void shuffle() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
        topIndex = 0;
    }

    Card topCard() {
        if (topIndex < (int)cards.size()) {
            return cards[topIndex++];
        }
        return Card();
    }

    void deal(Player& p);
};

// ===================== PLAYER =====================
class Player {
protected:
    string name;
    int chips;
    int currentBet;
    Hand hand;
    string mugshot;
    bool isInPlay;

public:
    Player(string name = "", int chips = 1000, string mugshot = "") {
        this->name = name;
        this->chips = chips;
        this->mugshot = mugshot;
        this->currentBet = 0;
        this->isInPlay = true;
    }

    virtual ~Player() {
    }

    string getName() const {
        return name;
    }

    int getChips() const {
        return chips;
    }

    int getCurrentBet() const {
        return currentBet;
    }

    bool getIsInPlay() const {
        return isInPlay;
    }

    Hand& getHand() {
        return hand;
    }

    const Hand& getHand() const {
        return hand;
    }

    void addChips(int amount) {
        chips += amount;
    }

    virtual void bet(int amount) {
        if (amount < 0) amount = 0;
        if (amount > chips) amount = chips;

        chips -= amount;
        currentBet += amount;

        cout << name << " bet " << amount << endl;
    }

    virtual void check() {
        cout << name << " check" << endl;
    }

    virtual void call(int targetBet) {
        int need = targetBet - currentBet;
        if (need < 0) need = 0;
        bet(need);
        cout << name << " call" << endl;
    }

    virtual void fold() {
        isInPlay = false;
        cout << name << " fold" << endl;
    }

    virtual void clear() {
        currentBet = 0;
        hand.clear();
        isInPlay = true;
    }

    virtual void raise(int amount) {
        bet(amount);
        cout << name << " raise " << amount << endl;
    }

    virtual void receiveCard(const Card& c) {
        hand.addCard(c);
    }

    virtual void showInfo() const {
        cout << "Name: " << name << endl;
        cout << "Chips: " << chips << endl;
        cout << "Bet: " << currentBet << endl;
        cout << "Hand: " << hand.toString() << endl;
        cout << "In play: " << (isInPlay ? "Yes" : "No") << endl;
    }
};

// ===================== HUMAN PLAYER =====================
class HumanPlayer : public Player {
public:
    HumanPlayer(string name = "", int chips = 1000, string mugshot = "")
        : Player(name, chips, mugshot) {
    }
};

// ===================== COMPUTER PLAYER =====================
class ComputerPlayer : public Player {
private:
    int difficulty;

public:
    ComputerPlayer(string name = "", int chips = 1000, int difficulty = 1, string mugshot = "")
        : Player(name, chips, mugshot) {
        this->difficulty = difficulty;
    }

    void makeMove() {
        if (!isInPlay) return;

        if (hand.isPair()) {
            int amount = difficulty * 50;
            if (amount > chips) amount = chips;
            raise(amount);
        } else {
            check();
        }
    }
};

// ===================== DECK::DEAL =====================
void Deck::deal(Player& p) {
    p.receiveCard(topCard());
}

// ===================== POKER GAME =====================
class PokerGame {
private:
    vector<Player*> players;   // 2..8 người chơi
    int currentPlayer;
    Deck deck;
    int round;

public:
    PokerGame() {
        currentPlayer = 0;
        round = 0;
    }

    void addPlayer(Player* p) {
        if ((int)players.size() < 8) {
            players.push_back(p);
        }
    }

    void playRound() {
        if ((int)players.size() < 2) {
            cout << "Can it nhat 2 nguoi choi.\n";
            return;
        }

        round++;
        currentPlayer = 0;
        int pot = 0;

        cout << "\n================ ROUND " << round << " ================\n";

        // reset
        for (int i = 0; i < (int)players.size(); i++) {
            players[i]->clear();
        }

        deck.reset();
        deck.shuffle();

        // moi nguoi dat cuoc mac dinh 100
        cout << "\n--- Dat cuoc ban dau ---\n";
        for (int i = 0; i < (int)players.size(); i++) {
            players[i]->bet(100);
            pot += 100;
        }

        // chia 2 la cho moi nguoi
        cout << "\n--- Chia bai ---\n";
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < (int)players.size(); i++) {
                deck.deal(*players[i]);
            }
        }

        // hien thi bai
        cout << "\n--- Bai tren tay ---\n";
        for (int i = 0; i < (int)players.size(); i++) {
            cout << players[i]->getName() << ": " << players[i]->getHand().toString() << endl;
        }

        // may tinh tu dong danh
        cout << "\n--- Luot choi ---\n";
        for (int i = 0; i < (int)players.size(); i++) {
            ComputerPlayer* cp = dynamic_cast<ComputerPlayer*>(players[i]);
            if (cp != NULL) {
                int oldBet = cp->getCurrentBet();
                cp->makeMove();
                pot += (cp->getCurrentBet() - oldBet);
            } else {
                players[i]->check();
            }
        }

        // tim nguoi thang
        vector<Player*> winners;
        for (int i = 0; i < (int)players.size(); i++) {
            if (!players[i]->getIsInPlay()) continue;

            if (winners.empty()) {
                winners.push_back(players[i]);
            } else {
                int cmp = players[i]->getHand().compareTo(winners[0]->getHand());

                if (cmp > 0) {
                    winners.clear();
                    winners.push_back(players[i]);
                } else if (cmp == 0) {
                    winners.push_back(players[i]);
                }
            }
        }

        cout << "\n--- Ket qua ---\n";
        if (winners.size() == 1) {
            winners[0]->addChips(pot);
            cout << "Nguoi thang: " << winners[0]->getName() << endl;
            cout << "Nhan duoc pot = " << pot << endl;
        } else {
            int share = pot / (int)winners.size();
            cout << "Hoa giua: ";
            for (int i = 0; i < (int)winners.size(); i++) {
                winners[i]->addChips(share);
                cout << winners[i]->getName();
                if (i != (int)winners.size() - 1) cout << ", ";
            }
            cout << endl;
            cout << "Moi nguoi nhan: " << share << endl;
        }

        cout << "\n--- So chip sau vong choi ---\n";
        for (int i = 0; i < (int)players.size(); i++) {
            cout << players[i]->getName() << ": " << players[i]->getChips() << " chips\n";
        }
    }
};

// ===================== MAIN =====================
int main() {
    HumanPlayer p1("Thanh", 1000);
    ComputerPlayer p2("May 1", 1000, 1);
    ComputerPlayer p3("May 2", 1000, 2);

    PokerGame game;
    game.addPlayer(&p1);
    game.addPlayer(&p2);
    game.addPlayer(&p3);

    game.playRound();
    game.playRound();

    return 0;
}