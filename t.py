def multiply_scalar_point(k):
    k_as_binary = bin(k)[2:]

    step = 0

    # decimal to binary conversion
    print("k = ({})10 = ({})2\n".format(k, k_as_binary))

    q = 1
    p = 1
    a = 18
    b = 15

    # header
    print("i\tki\t|\ta\t\tb\n--\t--\t|\t--\t\t--")

    for i in range(1, len(k_as_binary)):
        print(i, end="\t")

        current_bit = int(k_as_binary[i])
        print(current_bit, end="\t|\t")

        print("{}P+{}P=".format(q, q), end="")

        q = q + q
        a = q
        step += 1

        print("{}P\t".format(a), end="")

        if current_bit == 1:
            print("{}P+{}P=".format(q, p), end="")

            q = q + p
            b = q
            step += 1

            print("{}P\t".format(b), end="")

        b = 0

        print("")

    print("\nQ=kP is calculated in {}th step".format(step))

    return step

# Call the function with the desired value of k
k_value = 60
steps = multiply_scalar_point(k_value)
print(steps)
print("Total steps:", steps)
