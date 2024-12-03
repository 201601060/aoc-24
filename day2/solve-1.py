ans = 0

with open('day2.input', 'r') as input:
    with open('day2.output', 'w') as o:
        for line in input:
            nums = [int(n) for n in line.split()]
            dec = nums[0] > nums[1]
            fail = False
            for i in range(1, len(nums)):
                if abs(nums[i]-nums[i-1]) > 3 or nums[i]-nums[i-1] == 0 or \
                    (dec and nums[i] > nums[i-1]) or \
                        ((not dec) and nums[i] < nums[i-1]):
                    fail = True
                    break
            if not fail:
                o.write(str(nums)+'\n')
                ans += 1
    print(ans)
