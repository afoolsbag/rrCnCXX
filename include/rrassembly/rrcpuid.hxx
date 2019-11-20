//===-- CPUID Instruction Report Wrapper ------------------------*- C++ -*-===//
///
/// \file
/// \brief CPUID 指令报告包装
/// \sa <https://wikipedia.org/wiki/CPUID>
/// \sa <https://docs.microsoft.com/cpp/intrinsics/cpuid-cpuidex>
///
/// \version 2019-11-19
/// \since 2019-10-17
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRASSEMBLY_RRCPUID_HXX_
#define RRASSEMBLY_RRCPUID_HXX_

#ifndef NDEBUG
#error Abort. There are some code just for IntelliSense, please build without debug or disable the fragment.
#define __AVX__
#define __AVX2__
#define __AVX512F__
#endif

#ifndef RRASSEMBLY_AVX_SUPPORTED
# if defined(__clang__) && defined(__AVX__)
#  define RRASSEMBLY_AVX_SUPPORTED 1
# elif defined(__GNUC__) && defined(__AVX__)
#  define RRASSEMBLY_AVX_SUPPORTED 1
# elif defined(__INTEL_COMPILER) && defined(__AVX__)
#  define RRASSEMBLY_AVX_SUPPORTED 1
# elif defined(_MSC_VER) && defined(__AVX__)
#  define RRASSEMBLY_AVX_SUPPORTED 1
# else
#  define RRASSEMBLY_AVX_SUPPORTED 0
# endif
#endif

#ifndef RRASSEMBLY_AVX2_SUPPORTED
# if defined(_MSC_VER) && defined(__AVX2__)
#  define RRASSEMBLY_AVX2_SUPPORTED 1
# else
#  define RRASSEMBLY_AVX2_SUPPORTED 0
# endif
#endif

#ifndef RRASSEMBLY_AVX512_SUPPORTED
# if defined(_MSC_VER) && defined(__AVX512F__)
#  define RRASSEMBLY_AVX512_SUPPORTED 1
# else
#  define RRASSEMBLY_AVX512_SUPPORTED 0
# endif
#endif

#include <cstdint>
#include <bitset>
#include <string>

namespace rrassembly {

/// \brief CPUID 指令报告
class cpuid_report {
public:
    inline explicit cpuid_report();

    // F0EAX
    inline uint32_t highest_function_leaf() const;

    // F0EB/D/CX
    inline std::string manufacturer_id() const;

    // F1ECX
    inline bool is_sse3_supported() const noexcept;
    inline bool is_pclmulqdq_supported() const noexcept;
    inline bool is_dtes64_supported() const noexcept;
    inline bool is_monitor_supported() const noexcept;
    inline bool is_ds_cpl_supported() const noexcept;
    inline bool is_vmx_supported() const noexcept;
    inline bool is_smx_supported() const noexcept;
    inline bool is_est_supported() const noexcept;
    inline bool is_tm2_supported() const noexcept;
    inline bool is_ssse3_supported() const noexcept;
    inline bool is_cnxt_id_supported() const noexcept;
    inline bool is_sdbg_supported() const noexcept;
    inline bool is_fma_supported() const noexcept;
    inline bool is_cx16_supported() const noexcept;
    inline bool is_xtpr_supported() const noexcept;
    inline bool is_pdcm_supported() const noexcept;
    inline bool is_pcid_supported() const noexcept;
    inline bool is_dca_supported() const noexcept;
    inline bool is_sse4_1_supported() const noexcept;
    inline bool is_sse4_2_supported() const noexcept;
    inline bool is_x2apic_supported() const noexcept;
    inline bool is_movbe_supported() const noexcept;
    inline bool is_popcnt_supported() const noexcept;
    inline bool is_tsc_deadline_supported() const noexcept;
    inline bool is_aes_supported() const noexcept;
    inline bool is_xsave_supported() const noexcept;
    inline bool is_osxsave_supported() const noexcept;
    inline bool is_avx_supported() const noexcept;
    inline bool is_f16c_supported() const noexcept;
    inline bool is_rdrnd_supported() const noexcept;
    inline bool is_hypervisor_supported() const noexcept;

    // F1EDX
    inline bool is_fpu_supported() const noexcept;
    inline bool is_vme_supported() const noexcept;
    inline bool is_de_supported() const noexcept;
    inline bool is_pse_supported() const noexcept;
    inline bool is_tsc_supported() const noexcept;
    inline bool is_msr_supported() const noexcept;
    inline bool is_pae_supported() const noexcept;
    inline bool is_mce_supported() const noexcept;
    inline bool is_cx8_supported() const noexcept;
    inline bool is_apic_supported() const noexcept;
    inline bool is_sep_supported() const noexcept;
    inline bool is_mtrr_supported() const noexcept;
    inline bool is_pge_supported() const noexcept;
    inline bool is_mca_supported() const noexcept;
    inline bool is_cmov_supported() const noexcept;
    inline bool is_pat_supported() const noexcept;
    inline bool is_pse36_supported() const noexcept;
    inline bool is_psn_supported() const noexcept;
    inline bool is_clfsh_supported() const noexcept;
    inline bool is_ds_supported() const noexcept;
    inline bool is_acpi_supported() const noexcept;
    inline bool is_mmx_supported() const noexcept;
    inline bool is_fxsr_supported() const noexcept;
    inline bool is_sse_supported() const noexcept;
    inline bool is_sse2_supported() const noexcept;
    inline bool is_ss_supported() const noexcept;
    inline bool is_htt_supported() const noexcept;
    inline bool is_tm_supported() const noexcept;
    inline bool is_ia64_supported() const noexcept;
    inline bool is_pbe_supported() const noexcept;

    // F7EBX
    inline bool is_fsgsbase_supported() const noexcept;
    inline bool is_sgx_supported() const noexcept;
    inline bool is_bmi1_supported() const noexcept;
    inline bool is_hle_supported() const noexcept;
    inline bool is_avx2_supported() const noexcept;
    inline bool is_smep_supported() const noexcept;
    inline bool is_bmi2_supported() const noexcept;
    inline bool is_erms_supported() const noexcept;
    inline bool is_invpcid_supported() const noexcept;
    inline bool is_rtm_supported() const noexcept;
    inline bool is_pqm_supported() const noexcept;
    inline bool is_mpx_supported() const noexcept;
    inline bool is_pqe_supported() const noexcept;
    inline bool is_avx512_f_supported() const noexcept;
    inline bool is_avx512_dq_supported() const noexcept;
    inline bool is_rdseed_supported() const noexcept;
    inline bool is_adx_supported() const noexcept;
    inline bool is_smap_supported() const noexcept;
    inline bool is_avx512_ifma_supported() const noexcept;
    inline bool is_pcommit_supported() const noexcept;
    inline bool is_clflushopt_supported() const noexcept;
    inline bool is_clwb_supported() const noexcept;
    inline bool is_intel_pt_supported() const noexcept;
    inline bool is_avx512_pf_supported() const noexcept;
    inline bool is_avx512_er_supported() const noexcept;
    inline bool is_avx512_cd_supported() const noexcept;
    inline bool is_sha_supported() const noexcept;
    inline bool is_avx512_bw_supported() const noexcept;
    inline bool is_avx512_vl_supported() const noexcept;

    // F7ECX
    inline bool is_prefetchwt1_supported() const noexcept;
    inline bool is_avx512_vbmi_supported() const noexcept;
    inline bool is_umip_supported() const noexcept;
    inline bool is_pku_supported() const noexcept;
    inline bool is_ospke_supported() const noexcept;
    inline bool is_waitpkg_supported() const noexcept;
    inline bool is_avx512_vbmi2_supported() const noexcept;
    inline bool is_shstk_supported() const noexcept;
    inline bool is_gfni_supported() const noexcept;
    inline bool is_vaes_supported() const noexcept;
    inline bool is_vpclmulqdq_supported() const noexcept;
    inline bool is_avx512_vnni_supported() const noexcept;
    inline bool is_avx512_bitalg_supported() const noexcept;
    inline bool is_avx512_vpopcntdq_supported() const noexcept;
    inline bool is_mawau_supported() const noexcept;
    inline bool is_rdpid_supported() const noexcept;
    inline bool is_cldemote_supported() const noexcept;
    inline bool is_movdir_supported() const noexcept;
    inline bool is_movdir64b_supported() const noexcept;
    inline bool is_sgx_lc_supported() const noexcept;

    // F7EDX
    inline bool is_avx512_4vnniw_supported() const noexcept;
    inline bool is_avx512_4fmaps_supported() const noexcept;
    inline bool is_fsrm_supported() const noexcept;
    inline bool is_pconfig_supported() const noexcept;
    inline bool is_ibt_supported() const noexcept;
    inline bool is_spec_ctrl_supported() const noexcept;
    inline bool is_stibp_supported() const noexcept;
    inline bool is_capabilities_supported() const noexcept;
    inline bool is_ssbd_supported() const noexcept;

    // E0EAX
    inline uint32_t highest_extended_function_leaf() const;

    // E1ECX
    inline bool is_lahf_lm_supported() const noexcept;
    inline bool is_cmp_legacy_supported() const noexcept;
    inline bool is_svm_supported() const noexcept;
    inline bool is_extapic_supported() const noexcept;
    inline bool is_cr8_legacy_supported() const noexcept;
    inline bool is_abm_supported() const noexcept;
    inline bool is_sse4a_supported() const noexcept;
    inline bool is_misalignsse_supported() const noexcept;
    inline bool is_3dnowprefetch_supported() const noexcept;
    inline bool is_osvw_supported() const noexcept;
    inline bool is_ibs_supported() const noexcept;
    inline bool is_xop_supported() const noexcept;
    inline bool is_skinit_supported() const noexcept;
    inline bool is_wdt_supported() const noexcept;
    inline bool is_lwp_supported() const noexcept;
    inline bool is_fma4_supported() const noexcept;
    inline bool is_tce_supported() const noexcept;
    inline bool is_nodeid_msr_supported() const noexcept;
    inline bool is_tbm_supported() const noexcept;
    inline bool is_topoext_supported() const noexcept;
    inline bool is_perfctr_core_supported() const noexcept;
    inline bool is_perfctr_nb_supported() const noexcept;
    inline bool is_dbx_supported() const noexcept;
    inline bool is_perftsc_supported() const noexcept;
    inline bool is_pcx_l2i_supported() const noexcept;

    // E1EDX
    //inline bool is_fpu_supported() const noexcept;
    //inline bool is_vme_supported() const noexcept;
    //inline bool is_de_supported() const noexcept;
    //inline bool is_pse_supported() const noexcept;
    //inline bool is_tsc_supported() const noexcept;
    //inline bool is_msr_supported() const noexcept;
    //inline bool is_pae_supported() const noexcept;
    //inline bool is_mce_supported() const noexcept;
    //inline bool is_cx8_supported() const noexcept;
    //inline bool is_apic_supported() const noexcept;
    inline bool is_syscall_supported() const noexcept;
    //inline bool is_mtrr_supported() const noexcept;
    //inline bool is_pge_supported() const noexcept;
    //inline bool is_mca_supported() const noexcept;
    //inline bool is_cmov_supported() const noexcept;
    //inline bool is_pat_supported() const noexcept;
    //inline bool is_pse36_supported() const noexcept;
    inline bool is_mp_supported() const noexcept;
    inline bool is_nx_supported() const noexcept;
    inline bool is_mmxext_supported() const noexcept;
    //inline bool is_mmx_supported() const noexcept;
    //inline bool is_fxsr_supported() const noexcept;
    inline bool is_fxsr_opt_supported() const noexcept;
    inline bool is_pdpe1gb_supported() const noexcept;
    inline bool is_rdtscp_supported() const noexcept;
    inline bool is_lm_supported() const noexcept;
    inline bool is_3dnowext_supported() const noexcept;
    inline bool is_3dnow_supported() const noexcept;

    // E2/E3/E4
    inline std::string processor_brand() const;

private:
    // FUNCTION
    std::bitset<32> F0EAX {};  ///< EAX by EAX(leaf)=0b00000000'00000000'00000000'00000000u
    std::bitset<32> F0EBX {};  ///< EBX by EAX(leaf)=0b00000000'00000000'00000000'00000000u
    std::bitset<32> F0ECX {};  ///< ECX by EAX(leaf)=0b00000000'00000000'00000000'00000000u
    std::bitset<32> F0EDX {};  ///< EDX by EAX(leaf)=0b00000000'00000000'00000000'00000000u

    std::bitset<32> F1ECX {};  ///< ECX by EAX(leaf)=0b00000000'00000000'00000000'00000001u
    std::bitset<32> F1EDX {};  ///< EDX by EAX(leaf)=0b00000000'00000000'00000000'00000001u

    std::bitset<32> F7EBX {};  ///< EBX by EAX(leaf)=0b00000000'00000000'00000000'00000111u and EBX(sub-leaf)=0b00000000'00000000'00000000'00000000u
    std::bitset<32> F7ECX {};  ///< ECX by EAX(leaf)=0b00000000'00000000'00000000'00000111u and EBX(sub-leaf)=0b00000000'00000000'00000000'00000000u
    std::bitset<32> F7EDX {};  ///< EDX by EAX(leaf)=0b00000000'00000000'00000000'00000111u and EBX(sub-leaf)=0b00000000'00000000'00000000'00000000u

    // EXTENDED FUNCTION
    std::bitset<32> E0EAX {};  ///< EAX by EAX(leaf)=0b10000000'00000000'00000000'00000000u

    std::bitset<32> E1ECX {};  ///< EAX by ECX(leaf)=0b10000000'00000000'00000000'00000001u
    std::bitset<32> E1EDX {};  ///< EAX by EDX(leaf)=0b10000000'00000000'00000000'00000001u

    std::bitset<32> E2EAX {};  ///< EAX by EAX(leaf)=0b10000000'00000000'00000000'00000010u
    std::bitset<32> E2EBX {};  ///< EAX by EBX(leaf)=0b10000000'00000000'00000000'00000010u
    std::bitset<32> E2ECX {};  ///< EAX by ECX(leaf)=0b10000000'00000000'00000000'00000010u
    std::bitset<32> E2EDX {};  ///< EAX by EDX(leaf)=0b10000000'00000000'00000000'00000010u

    std::bitset<32> E3EAX {};  ///< EAX by EAX(leaf)=0b10000000'00000000'00000000'00000011u
    std::bitset<32> E3EBX {};  ///< EAX by EBX(leaf)=0b10000000'00000000'00000000'00000011u
    std::bitset<32> E3ECX {};  ///< EAX by ECX(leaf)=0b10000000'00000000'00000000'00000011u
    std::bitset<32> E3EDX {};  ///< EAX by EDX(leaf)=0b10000000'00000000'00000000'00000011u

    std::bitset<32> E4EAX {};  ///< EAX by EAX(leaf)=0b10000000'00000000'00000000'00000100u
    std::bitset<32> E4EBX {};  ///< EAX by EBX(leaf)=0b10000000'00000000'00000000'00000100u
    std::bitset<32> E4ECX {};  ///< EAX by ECX(leaf)=0b10000000'00000000'00000000'00000100u
    std::bitset<32> E4EDX {};  ///< EAX by EDX(leaf)=0b10000000'00000000'00000000'00000100u
};

}

#include "rrcpuid.inl"

#endif
