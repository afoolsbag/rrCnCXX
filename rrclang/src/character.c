/** \file
 *  \sa <http://en.cppreference.com/w/c/language/arithmetic_types#Character_types>
 *  \author zhengrr
 *  \date 2016-6-27 – 11-25
 *  \copyright The MIT License
 */
static char digit_to_hex_char(const int digit)
{
        return "0123456789ABCDEF"[digit];
}
