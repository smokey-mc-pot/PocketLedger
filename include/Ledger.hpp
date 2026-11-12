#pragma once
#include "Transaction.hpp"
#include <cstddef>
#include <vector>
#include <cstdint>

class Ledger {
public:
	Ledger& operator+=(const Transaction& transaction);
	Ledger operator+(const Ledger& other) const;
	const Transaction& operator[](std::size_t index) const;

	[[nodiscard]] std::size_t size() const;
	[[nodiscard]] std::int64_t balance() const;
	bool erase(std::size_t index);

private:
	std::vector<Transaction> m_ledger;
};