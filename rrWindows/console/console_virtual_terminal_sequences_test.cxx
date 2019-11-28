/// \copyright Unlicense

#include <gtest/gtest.h>

#include "rrwindows/rrwindows.hxx"

namespace rrwindows {

TEST(console_virtual_terminal_sequences, alloc_error_message)
{
    enable_virtual_terminal_mode();

    puts(VTFRED _T("Red text") VTFDEF);
    puts(VTFGRN _T("Green text") VTFDEF);
    puts(VTFYEL _T("Yellow text") VTFDEF);
    puts(VTFBLU _T("Blue text") VTFDEF);

    disable_virtual_terminal_mode();
}

}
