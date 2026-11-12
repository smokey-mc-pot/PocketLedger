#include <gtest/gtest.h>
#include "Ledger.hpp"
#include "Transaction.hpp"

TEST(LedgerTest, StartsEmpty) {
	const Ledger ledger;

	EXPECT_EQ(ledger.size(), 0);
	EXPECT_EQ(ledger.balance(), 0);
}

TEST(LedgerTest, BalanceUpdatesAfterRemovingIncome) {
	Ledger ledger;
	const Transaction transaction_1{Transaction::Kind::income, 1000, "salary", ""};
	const Transaction transaction_2{Transaction::Kind::expense, 350, "food", ""};
	
	ledger += transaction_1;
	ledger += transaction_2;

	EXPECT_EQ(ledger.balance(), 650);
	EXPECT_EQ(ledger.size(), 2);
	ASSERT_TRUE(ledger.erase(0));
	EXPECT_EQ(ledger.size(), 1);
	EXPECT_EQ(ledger.balance(), -350);
}

TEST(LedgerTest, EraseInvalidIndexLeavesLedgerUnchanged) {
	Ledger ledger;
	const Transaction transaction{Transaction::Kind::income, 1000, "salary", ""};
	
	ledger += transaction;

	EXPECT_FALSE(ledger.erase(1));
	ASSERT_EQ(ledger.size(), 1);
	EXPECT_EQ(ledger[0], transaction);
}

TEST(LedgerTest, AdditionPreservesOrderAndLeavesOperandsUnchanged) {
	Ledger ledger_1, ledger_2;
	const Transaction transaction_1{Transaction::Kind::income, 1000, "salary", ""};
	const Transaction transaction_2{Transaction::Kind::expense, 350, "food", ""};
	
	ledger_1 += transaction_1;
	ledger_2 += transaction_2;

	auto new_ledger = ledger_1 + ledger_2;

	ASSERT_EQ(ledger_1.size(), 1);
	ASSERT_EQ(ledger_2.size(), 1);
	EXPECT_EQ(ledger_1[0], transaction_1);
	EXPECT_EQ(ledger_2[0], transaction_2);

	ASSERT_EQ(new_ledger.size(), 2);
	EXPECT_EQ(new_ledger[0], transaction_1);
	EXPECT_EQ(new_ledger[1], transaction_2);
}