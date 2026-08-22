class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum1 = 0
        prod = 1

        num = n
        while num:
            sum1 += num % 10
            prod *= num % 10
            num //= 10

        return n % (sum1 + prod) == 0
        