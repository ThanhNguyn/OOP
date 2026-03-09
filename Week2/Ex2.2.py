import math

# 1) Volume sphere r=5 ( the tich hinh cau r=5)
r = 5
volume = (4/3) * math.pi * r**3
print("1) Volume:", volume)

# 2) Wholesale cost for 60 copies ( gia ban si 60 cuon )
cover_price = 24.95
discount = 0.40
copies = 60

book_cost = cover_price * (1 - discount) * copies
shipping = 3 + (copies - 1) * 0.75
total = book_cost + shipping
print("2) Wholesale cost: $", round(total, 2)) # lam tron 2 chu so sau dau phay

# 3) Breakfast time ( thoi gian an sang )
start = 6*60*60 + 52*60         # 6:52:00 to sec
easy = 8*60 + 15               # 8:15 per mile
tempo = 7*60 + 12              # 7:12 per mile
# e ko hieu 8:15 per mile la 8h15m hay 8m15s ma 1miles khoang 1.5km 
# nen e nghi la phut tuong tu voi 7:12
run_time = easy + 3*tempo + easy
arrive = start + run_time

h = arrive // 3600
m = (arrive % 3600) // 60
s = arrive % 60
print(f"3) Get home at: {h:02d}:{m:02d}:{s:02d}")
