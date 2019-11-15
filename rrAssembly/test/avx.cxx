/// \copyright Unlicense

using namespace std;

#if 0
void show_cpu_supported(std::ostream &os)
{
    const cpuid_report rep;
    os << "OSXSAVE:           " << rep.is_osxsave_supported() << '\n';
    os << "AES:               " << rep.is_aes_supported() << '\n';
    os << "FMA:               " << rep.is_fma_supported() << '\n';
    os << "PCLMULQDQ:         " << rep.is_pclmulqdq_supported() << '\n';
    os << "AVX:               " << rep.is_avx_supported() << '\n';
    os << "AVX2:              " << rep.is_avx2_supported() << '\n';
    os << "AVX-512-F:         " << rep.is_avx512_f_supported() << '\n';
    os << "AVX-512-CD:        " << rep.is_avx512_cd_supported() << '\n';
    os << "AVX-512-ER:        " << rep.is_avx512_er_supported() << '\n';
    os << "AVX-512-PF:        " << rep.is_avx512_pf_supported() << '\n';
    os << "AVX-512-VL:        " << rep.is_avx512_vl_supported() << '\n';
    os << "AVX-512-DQ:        " << rep.is_avx512_dq_supported() << '\n';
    os << "AVX-512-BW:        " << rep.is_avx512_bw_supported() << '\n';
    os << "AVX-512-IFMA:      " << rep.is_avx512_ifma_supported() << '\n';
    os << "AVX-512-VBMI:      " << rep.is_avx512_vbmi_supported() << '\n';
    os << "AVX-512-4VNNIW:    " << rep.is_avx512_4vnniw_supported() << '\n';
    os << "AVX-512-4FMAPS:    " << rep.is_avx512_4fmaps_supported() << '\n';
    os << "AVX-512-VPOPCNTDQ: " << rep.is_avx512_vpopcntdq_supported() << '\n';
    os << "AVX-512-VNNI:      " << rep.is_avx512_vnni_supported() << '\n';
    os << "AVX-512-VBMI2:     " << rep.is_avx512_vbmi2_supported() << '\n';
    os << "AVX-512-BITALG:    " << rep.is_avx512_bitalg_supported() << '\n';
}
#endif
