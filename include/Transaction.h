#pragma once
#include <string>
#include <cstdint>
#include <utility>

class Transaction {
public:
	enum class Kind { 
		income, 
		expense 
	};

	Transaction(Kind kind, std::int64_t amount, std::string category, std::string note) : m_kind{kind}, m_amount{amount}, m_category{std::move(category)}, m_note{std::move(note)} {}

	bool operator==(const Transaction& other) const;

	[[nodiscard]] Kind kind() const;
	[[nodiscard]] std::int64_t amount() const;
	[[nodiscard]] const std::string& category() const;
	[[nodiscard]] const std::string& note() const;
	[[nodiscard]] std::int64_t signed_amount() const;

private:
	Kind m_kind;
	std::int64_t m_amount{0};
	std::string m_category;
	std::string m_note;
};