/** \file
 *  \brief “掷骰子”库
 *  \author zhengrr
 *  \date 2018-1-3
 *  \copyright The MIT License */

#ifdef __cplusplus
# define EXPORT extern "C" __declspec (dllexport)
#else
# define EXPORT __declspec (dllexport)
#endif

/** \brief 掷骰子·美国国家标准学会适配 */
EXPORT INT CALLBACK DiceA();

/** \brief 掷骰子·宽字符适配 */
EXPORT INT CALLBACK DiceW();

#ifdef UNICODE
# define Dice DiceW
#else
# define Dice DiceA
#endif
