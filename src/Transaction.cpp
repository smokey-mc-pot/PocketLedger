#include "Transaction.h"
	
Transaction::Kind Transaction::kind() const {
	return m_kind;
} 

std::int64_t Transaction::amount() const {
	return m_amount;
}

const std::string& Transaction::category() const {
	return m_category;
} 

const std::string& Transaction::note() const {
	return m_note;
}

std::int64_t Transaction::signed_amount() const {
	return m_kind == Kind::income? m_amount : -1 * m_amount;
}

bool Transaction::operator==(const Transaction& other) const {
	return m_kind == other.m_kind && m_amount == other.m_amount && m_category == other.m_category && m_note == other.m_note;
}