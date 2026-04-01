from math import gcd, isqrt

LIMIT = 1_500_000

print("Keeping perimeter values under 1,500,00, find the right triangles with integer length sides.")


# counts[p] = number of distinct integer right triangles with perimeter p
counts = [0] * (LIMIT + 1)

m_limit = isqrt(LIMIT // 2) + 1

for m in range(2, m_limit):
    for n in range(1, m):
        # primitive triple conditions
        if ((m - n) % 2 == 1) and (gcd(m, n) == 1):
            p0 = 2 * m * (m + n)   # primitive perimeter

            if p0 > LIMIT:
                break

            # count all multiples of the primitive perimeter
            for p in range(p0, LIMIT + 1, p0):
                counts[p] += 1

# Number of perimeter values with exactly one integer right triangle
answer = sum(1 for p in counts if p == 1)

print(answer)
