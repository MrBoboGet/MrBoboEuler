#include <vector>
#include <string>
class BigInteger
{
public:
	std::vector<unsigned long int> IntParts = std::vector<unsigned long int>(0);

	BigInteger(int NumberOf32BitInts);
	BigInteger();

	BigInteger operator+(const BigInteger& OtherBig);

	std::string ToString();
	friend bool operator<(const BigInteger& Big1,const BigInteger& Big2);
	friend bool operator>(const BigInteger& Big1,const BigInteger& Big2);
	friend bool operator>=(const BigInteger& Big1,const BigInteger& Big2);
	friend bool operator<=(const BigInteger& Big1,const BigInteger& Big2);
	friend BigInteger operator*(const BigInteger& Big, int Konstant);
	friend BigInteger operator*(int Konstant, const BigInteger& Big);
	BigInteger operator=(int OtherInt);
};