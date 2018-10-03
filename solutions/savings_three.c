// NUS Students' Computing Club Academic Liaison Cell
// Mock Practical Exam (CS1010) AY 18/19 Sem 1
// Task 3
//
// Program Description:
// Computes the minimum number of years for Bank B to be better than Bank A.
// Bank A uses a% simple interest rate, while Bank B uses b% compound interest rate, and a > b.
//
// Author: Ng Tzer Bin

#include "cs1010.h"

double compute_interest(double, double);
double compute_with_simple_rate(double, double, long);
double compute_with_compound_rate(double, double, long);
double compute_min_years(double, double, double);

int main() {

    // Get the three inputs, and change the interest rate to decimal instead of percentage.
    double principal = cs1010_read_double();
    double simple_rate = cs1010_read_double() / 100.0;
    double compound_rate = cs1010_read_double() / 100.0;

    // Compute the minimum number of years, and print it out.
    cs1010_println_long(compute_min_years(principal, simple_rate, compound_rate));
    
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

// Computes the minimum number of years for Bank B to be better than Bank A.
double compute_min_years(double principal, double simple_rate, double compound_rate) {

    int years = 0;
    float simple_amount = principal;
    float compound_amount = principal;

    // If the compounded amount is less than the simple amount,
    // increment the year by 1, and calculate both amounts for each year.
    while (simple_amount >= compound_amount) {
        years += 1;
        simple_amount = compute_with_simple_rate(principal, simple_rate, years);
        compound_amount = compute_with_compound_rate(principal, compound_rate, years);
    }

    return years;
}