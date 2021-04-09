/**
 * @brief      Modulo operator that handles negative numbers
 *
 * @param[in]  number 
 * @param[in]  modulo
 *
 * @return     modulo operation result
 */
int my_modulo(int number, int modulo)
{
	while (number < 0)
	{
		number += modulo;
	}

	return number % modulo;
}