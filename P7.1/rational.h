

struct RATIONAL_NUM
{
	int numerator;
	int denominator;	
};//未进行信息隐藏，后续练习改正
RATIONAL_NUM GetRationalNum(int numerator,int denominator);
RATIONAL_NUM Simplify(const RATIONAL_NUM *prational);
RATIONAL_NUM Add(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b);
RATIONAL_NUM Subtract(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b);
RATIONAL_NUM Multiply(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b);
RATIONAL_NUM Divide(const RATIONAL_NUM *prational_a,const RATIONAL_NUM *prational_b);

