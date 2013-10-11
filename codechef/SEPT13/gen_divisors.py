def gen_divisors(prime_list):
    elts = sorted(set(prime_list))
    numelts = len(elts)

    # Split on the number of copies of elts[i].
    def gen_inner(i):
        if i >= numelts:
            yield 1
            return
        thiselt = elts[i]
        thismax = prime_list.count(thiselt)

        # powers <- [thiselt**i for i in range(thismax+1)],
        # but using only thismax multiplications.
        powers = [1]
        for j in xrange(thismax):
            powers.append(powers[-1] * thiselt)

        for d in gen_inner(i+1):
            for prime_power in powers:
                yield prime_power * d

    for d in gen_inner(0):
        yield d
