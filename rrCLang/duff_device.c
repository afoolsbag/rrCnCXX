/** \file
 *  \brief Duff's Device.
 *  \details 一种串行复制的优化实现，通过展开循环进行优化。
 *  \author zhengrr
 *  \date 2016-11-10 – 25
 *  \copyright The MIT License
 */
static void duff_device(register short *to,
                        register short *from,
                        register int count)
{
        switch (count % 8) {
        case 0:        do {    *to = *from++;
        case 7:                *to = *from++;
        case 6:                *to = *from++;
        case 5:                *to = *from++;
        case 4:                *to = *from++;
        case 3:                *to = *from++;
        case 2:                *to = *from++;
        case 1:                *to = *from++;
                       } while ((count -= 8) > 0);
        }
}
