from decimal import Decimal

def cal(r):
    d = Decimal(r) ** Decimal(5000) - Decimal(1)
    n = Decimal(r) - Decimal(1)
    ans = Decimal(900) * d / n + Decimal(3) * d / (n ** Decimal(2)) - (Decimal(3 * r) ** Decimal(5000))/n
    return ans 


print(cal(1.1))	
l, r = 1.0,2.0
for t in range(200):
    mid = (l + r) / 2
    if(cal(mid) > Decimal('-600000000000')):
        l = mid
    else:
        r = mid	

print(l)		
