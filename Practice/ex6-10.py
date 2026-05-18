n = int(input())
nums = list(map(int, input().split()))

nums = sorted(nums[:n])
print(" ".join(map(str, nums)))
