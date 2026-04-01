from math import isqrt


print('''Excercise of the use of Euler's Totient Function, e.g. "phi function", to find an output number that is a digital permutation of the input number with minimum ratio of input to output.
''')

def digit_signature(n: int) -> tuple[int, ...]:
    counts = [0] * 10
    while n > 0:
        counts[n % 10] += 1
        n //= 10
    return tuple(counts)


def compute_totients(limit: int) -> list[int]:
    phi = list(range(limit + 1))
    for i in range(2, limit + 1):
        if phi[i] == i:
            for j in range(i, limit + 1, i):
                phi[j] -= phi[j] // i
    return phi


def find_min_totient_permutation(limit: int) -> tuple[int, int, float]:
    phi = compute_totients(limit)

    best_n = None
    best_phi = None
    best_ratio = float("inf")

    for n in range(2, limit):
        p = phi[n]
        if digit_signature(n) == digit_signature(p):
            ratio = n / p
            if ratio < best_ratio:
                best_ratio = ratio
                best_n = n
                best_phi = p

    return best_n, best_phi, best_ratio


limit = 10_000_000
best_n, best_phi, best_ratio = find_min_totient_permutation(limit)

print(best_n, best_phi, best_ratio)


print('''\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n''')


def sieve_primes(limit: int) -> list[int]:
    """
    Return all primes <= limit using the sieve of Eratosthenes.
    """
    if limit < 2:
        return []

    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[0:2] = b"\x00\x00"

    for p in range(2, isqrt(limit) + 1):
        if is_prime[p]:
            start = p * p
            step = p
            is_prime[start:limit + 1:step] = b"\x00" * (((limit - start) // step) + 1)

    return [i for i in range(2, limit + 1) if is_prime[i]]


def digit_signature(n: int) -> tuple[int, ...]:
    """
    Return a digit-frequency signature for fast permutation checking.
    """
    counts = [0] * 10
    while n > 0:
        counts[n % 10] += 1
        n //= 10
    return tuple(counts)

def find_min_totient_permutation_semiprime(limit: int) -> tuple[int, int, float]:
    """
    Search n < limit, restricting to semiprimes n = p*q, where p and q are prime.
    Finds n such that phi(n) is a digit permutation of n and n/phi(n) is minimized.

    Returns:
        (best_n, best_phi, best_ratio)
    """
    primes = sieve_primes(limit)
    best_n = None
    best_phi = None
    best_ratio = float("inf")

    # The best ratio tends to come from p and q both fairly large,
    # so iterate downward to reach strong candidates early.
    for i in range(len(primes) - 1, -1, -1):
        p = primes[i]

        for j in range(i, -1, -1):
            q = primes[j]
            n = p * q

            if n >= limit:
                continue

            phi_n = (p - 1) * (q - 1)
            ratio = n / phi_n

            # Since we're seeking a minimum ratio, skip if already worse
            if ratio >= best_ratio:
                # For fixed p, smaller q usually makes ratio worse,
                # so we can often break here.
                break

            if digit_signature(n) == digit_signature(phi_n):
                best_n = n
                best_phi = phi_n
                best_ratio = ratio

    return best_n, best_phi, best_ratio


if __name__ == "__main__":
    limit = 10_000_000
    best_n, best_phi, best_ratio = find_min_totient_permutation_semiprime(limit)

    print(f"best n    = {best_n}")
    print(f"phi(n)    = {best_phi}")
    print(f"n/phi(n)  = {best_ratio}")


