//Legendre’s three-square theorem states that a natural number can be represented as the sum
//of three squares of integers if and only if n is not of the form : n = 4a (8b+7), for non-negative integers a and b.


//Lagrange’s four-square theorem, also known as Bachet’s conjecture, states that every natural
//number can be represented as the sum of four integer squares, where each integer is non-negative.


the minimum number of squares to represent any number N can be found. Follow the steps below:

If N is a perfect square, then the result is 1.
If N can be expressed as the sum of two squares, then the result is 2.
If N cannot be expressed in the form of N = 4 ^ a (8b + 7), where a and b are non - negative integers, then the result is 3 by Legendre’s three - square theorem.
If all the above conditions are not satisfied, then by Lagrange’s four - square theorem, the result is 4.

bool isPerfectSquare(int n) {
    int i = sqrt(n);

    if (n == i * i)
        return true;
    return false;
}
bool legendre(int n) {
    while (n % 4 == 0) {
        n /= 4;
    }
    if (n % 8 != 7)
        return true;

    return false;
}

int min_squares(int n) { // O(sqrt(n))
    if (isPerfectSquare(n))
        return 1;

    for (int i = 1; i * i < n; i++) {
        if (isPerfectSquare(n - i * i))
            return 2;
    }

    if (legendre(n))
        return 3;

    return 4; // due to larange theorem
}
