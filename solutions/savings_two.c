// NUS Students' Computing Club Academic Liaison Cell
// Mock Practical Exam (CS1010) AY 18/19 Sem 1
// Task 2
//
// Program Description:
// Computes the final savings after n years with principal amount $C not using formula.
// Bank A uses a% simple interest rate, while Bank B uses b% compound interest rate.
//
// Author: Ng Tzer Bin

#include "cs1010.h"

double compute_interest(double, double);
double compute_with_simple_rate(double, double, long);
double compute_with_compound_rate(double, double, long);

int main() {

    // Get the four inputs, and change the interest rate to decimal instead of percentage.
    double principal = cs1010_read_double();
    double simple_rate = cs1010_read_double() / 100.0;
    double compound_rate = cs1010_read_double() / 100.0;
    long years = cs1010_read_long();

    // Compute the final amount in each bank, and print it out.
    cs1010_println_double(compute_with_simple_rate(principal, simple_rate, years));
    cs1010_println_double(compute_with_compound_rate(principal, compound_rate, years));

    return 0;
}

// Computes the interest, given the principal amount and the interest rate.
double compute_interest(double principal, double rate) {
    return principal * rate;
}

// Computes the final amount in Bank A using the the compute_interest function.
double compute_with_simple_rate(double principal, double simple_rate, long years) {
    
    int i;  // Counter

    // Note the final amount.
    double final_amount = principal;

    // Add the interest to the final amount for each year.
    for (i = 0; i < years; i ++) {
        final_amount += compute_interest(principal, simple_rate);
    }

    return final_amount;

}

// Computes the final amount in Bank B using the the compute_interest function.
double compute_with_compound_rate(double principal, double compound_rate, long years) {

    int i;  // Counter

    // Note the final amount.
    double final_amount = principal;

    // Add the interest to the final amount for each year.
    // Take note that the interest is using the final amount in previous year as the principal amount.
    for (i = 0; i < years; i ++) {
        final_amount += compute_interest(final_amount, compound_rate);
    }

    return final_amount;
}
