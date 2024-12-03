ans = 0


def check_safe(nums):
    dec = nums[0] > nums[1]
    is_safe = True
    for i in range(1, len(nums)):
        if abs(nums[i]-nums[i-1]) > 3 or nums[i]-nums[i-1] == 0 or \
            (dec and nums[i] > nums[i-1]) or \
                ((not dec) and nums[i] < nums[i-1]):
            is_safe = not is_safe
            break
    return is_safe


with open('day2.input', 'r') as input:
    for line in input:
        nums = [int(n) for n in line.split()]
        if check_safe(nums):
            ans += 1
        else:
            is_safe = False
            for i in range(0, len(nums)):
                temp = nums[:i] + nums[i+1:]
                if check_safe(temp):
                    ans += 1
                    break
    print(ans)
