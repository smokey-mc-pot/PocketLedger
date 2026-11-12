#include "Ledger.hpp"
#include "Transaction.hpp"
#include <cstddef>
#include <vector>
#include <cstdint>

Ledger& Ledger::operator+=(const Transaction& transaction) {
	m_ledger.push_back(transaction);
	return *this;
}

Ledger Ledger::operator+(const Ledger& other) const {
	Ledger tmp;

	tmp.m_ledger.reserve(m_ledger.size() + other.m_ledger.size());

	tmp.m_ledger.insert(tmp.m_ledger.end(), m_ledger.begin(), m_ledger.end());
	tmp.m_ledger.insert(tmp.m_ledger.end(), other.m_ledger.begin(), other.m_ledger.end());

	return tmp;
}

const Transaction& Ledger::operator[](std::size_t index) const {
	return m_ledger[index];
}

[[nodiscard]] std::size_t Ledger::size() const {
	return m_ledger.size();
}

[[nodiscard]] std::int64_t Ledger::balance() const {
	std::int64_t total{0};

	for (const auto& item : m_ledger) {
		total += item.signed_amount();
	}

	return total;
}

bool Ledger::erase(std::size_t index) {
	if (index >= size()) {
		return false;
	}

	using Offset = std::vector<Transaction>::difference_type;
	m_ledger.erase(m_ledger.begin() + static_cast<Offset>(index));

	return true;
}