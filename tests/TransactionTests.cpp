#include <gtest/gtest.h>
#include "Transaction.hpp"

TEST(TransactionTest, ExpenseHasNegativeSignedAmount) {
	const Transaction expense{Transaction::Kind::expense, 350, "food", ""};

	EXPECT_EQ(expense.signed_amount(), -350);
}