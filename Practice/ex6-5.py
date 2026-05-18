n = int(input())
nums = list(map(int, input().split()))

chan = sum(1 for x in nums[:n] if x % 2 == 0)
le = n - chan

print(f"Chẵn: {chan}, Lẻ: {le}")
