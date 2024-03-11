#pragma once
class PayService
{

public:

	void updatePrice(float);

	float getSubtotal();
	float getTax();
	float getTotal();
	
private:

	float m_subtotal{ 0.f };
	float m_tax{ 0.f };
	const float m_taxRate{ 0.05f };
	float m_total{ 0.f };

	float calculateTax();
	float calculateTotal();

	void setSubtotal(float);
	void setTax(float);
	void setTotal(float);

};