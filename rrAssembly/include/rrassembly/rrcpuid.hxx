//===-- CPUID Instruction Report Wrapper ------------------------*- C++ -*-===//
///
/// \file
/// \brief CPUID 指令报告包装
/// \sa <https://wikipedia.org/wiki/CPUID>
/// \sa <https://docs.microsoft.com/cpp/intrinsics/cpuid-cpuidex>
///
/// \version 2019-10-18
/// \since 2019-10-17
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRASSEMBLY_RRCPUID_HXX_
#define RRASSEMBLY_RRCPUID_HXX_

#include <cstdint>
#include <cstring>
#include <bitset>
#include <array>
#include <string>

#include <intrin.h>  // intrinsics

namespace rrassembly {

class cpuid_report {
public:
    inline explicit cpuid_report();

    std::string manufacturer_id() const { return manufacturer_id_; }
    inline bool is_manufactured_by_amd() const;
    inline bool is_manufactured_by_centaur() const;
    inline bool is_manufactured_by_cyrix() const;
    inline bool is_manufactured_by_hygon() const;
    inline bool is_manufactured_by_intel() const;
    inline bool is_manufactured_by_transmeta() const;
    inline bool is_manufactured_by_nsc() const;
    inline bool is_manufactured_by_nexgen() const;
    inline bool is_manufactured_by_rise() const;
    inline bool is_manufactured_by_sis() const;
    inline bool is_manufactured_by_umc() const;
    inline bool is_manufactured_by_via() const;
    inline bool is_manufactured_by_vortex() const;

    // EAX=000000001: ECX

    inline bool is_sse3_supported() const;
    inline bool is_pclmulqdq_supported() const;
    inline bool is_dtes64_supported() const;
    inline bool is_monitor_supported() const;
    inline bool is_ds_cpl_supported() const;
    inline bool is_vmx_supported() const;
    inline bool is_smx_supported() const;
    inline bool is_est_supported() const;
    inline bool is_tm2_supported() const;
    inline bool is_ssse3_supported() const;
    inline bool is_cnxt_id_supported() const;
    inline bool is_sdbg_supported() const;
    inline bool is_fma_supported() const;
    inline bool is_cx16_supported() const;
    inline bool is_xtpr_supported() const;
    inline bool is_pdcm_supported() const;
    inline bool is_pcid_supported() const;
    inline bool is_dca_supported() const;
    inline bool is_sse4_1_supported() const;
    inline bool is_sse4_2_supported() const;
    inline bool is_x2apic_supported() const;
    inline bool is_movbe_supported() const;
    inline bool is_popcnt_supported() const;
    inline bool is_tsc_deadline_supported() const;
    inline bool is_aes_supported() const;
    inline bool is_xsave_supported() const;
    inline bool is_osxsave_supported() const;
    inline bool is_avx_supported() const;
    inline bool is_f16c_supported() const;
    inline bool is_rdrnd_supported() const;
    inline bool is_hypervisor_supported() const;

    // EAX=000000001: EDX

    inline bool is_fpu_supported() const;
    inline bool is_vme_supported() const;
    inline bool is_de_supported() const;
    inline bool is_pse_supported() const;
    inline bool is_tsc_supported() const;
    inline bool is_msr_supported() const;
    inline bool is_pae_supported() const;
    inline bool is_mce_supported() const;
    inline bool is_cx8_supported() const;
    inline bool is_apic_supported() const;
    inline bool is_sep_supported() const;
    inline bool is_mtrr_supported() const;
    inline bool is_pge_supported() const;
    inline bool is_mca_supported() const;
    inline bool is_cmov_supported() const;
    inline bool is_pat_supported() const;
    inline bool is_pse36_supported() const;
    inline bool is_psn_supported() const;
    inline bool is_clfsh_supported() const;
    inline bool is_ds_supported() const;
    inline bool is_acpi_supported() const;
    inline bool is_mmx_supported() const;
    inline bool is_fxsr_supported() const;
    inline bool is_sse_supported() const;
    inline bool is_sse2_supported() const;
    inline bool is_ss_supported() const;
    inline bool is_htt_supported() const;
    inline bool is_tm_supported() const;
    inline bool is_ia64_supported() const;
    inline bool is_pbe_supported() const;

    // EAX=000000001, ECX=00000000: EBX

    inline bool is_fsgsbase_supported() const;
    inline bool is_sgx_supported() const;
    inline bool is_bmi1_supported() const;
    inline bool is_hle_supported() const;
    inline bool is_avx2_supported() const;
    inline bool is_smep_supported() const;
    inline bool is_bmi2_supported() const;
    inline bool is_erms_supported() const;
    inline bool is_invpcid_supported() const;
    inline bool is_rtm_supported() const;
    inline bool is_pqm_supported() const;
    inline bool is_mpx_supported() const;
    inline bool is_pqe_supported() const;
    inline bool is_avx512_f_supported() const;
    inline bool is_avx512_dq_supported() const;
    inline bool is_rdseed_supported() const;
    inline bool is_adx_supported() const;
    inline bool is_smap_supported() const;
    inline bool is_avx512_ifma_supported() const;
    inline bool is_pcommit_supported() const;
    inline bool is_clflushopt_supported() const;
    inline bool is_clwb_supported() const;
    inline bool is_intel_pt_supported() const;
    inline bool is_avx512_pf_supported() const;
    inline bool is_avx512_er_supported() const;
    inline bool is_avx512_cd_supported() const;
    inline bool is_sha_supported() const;
    inline bool is_avx512_bw_supported() const;
    inline bool is_avx512_vl_supported() const;

    // EAX=000000001, ECX=00000000: ECX

    inline bool is_prefetchwt1_supported() const;
    inline bool is_avx512_vbmi_supported() const;
    inline bool is_umip_supported() const;
    inline bool is_pku_supported() const;
    inline bool is_ospke_supported() const;
    inline bool is_waitpkg_supported() const;
    inline bool is_avx512_vbmi2_supported() const;
    inline bool is_shstk_supported() const;
    inline bool is_gfni_supported() const;
    inline bool is_vaes_supported() const;
    inline bool is_vpclmulqdq_supported() const;
    inline bool is_avx512_vnni_supported() const;
    inline bool is_avx512_bitalg_supported() const;
    inline bool is_avx512_vpopcntdq_supported() const;
    inline bool is_mawau_supported() const;
    inline bool is_rdpid_supported() const;
    inline bool is_cldemote_supported() const;
    inline bool is_movdir_supported() const;
    inline bool is_movdir64b_supported() const;
    inline bool is_sgx_lc_supported() const;

    // EAX=000000001, ECX=00000000: EDX

    inline bool is_avx512_4vnniw_supported() const;
    inline bool is_avx512_4fmaps_supported() const;
    inline bool is_fsrm_supported() const;
    inline bool is_pconfig_supported() const;
    inline bool is_ibt_supported() const;
    inline bool is_spec_ctrl_supported() const;
    inline bool is_stibp_supported() const;
    inline bool is_capabilities_supported() const;
    inline bool is_ssbd_supported() const;

    // EAX=800000001: ECX

    inline bool is_lahf_lm_supported() const;
    inline bool is_cmp_legacy_supported() const;
    inline bool is_svm_supported() const;
    inline bool is_extapic_supported() const;
    inline bool is_cr8_legacy_supported() const;
    inline bool is_abm_supported() const;
    inline bool is_sse4a_supported() const;
    inline bool is_misalignsse_supported() const;
    inline bool is_3dnowprefetch_supported() const;
    inline bool is_osvw_supported() const;
    inline bool is_ibs_supported() const;
    inline bool is_xop_supported() const;
    inline bool is_skinit_supported() const;
    inline bool is_wdt_supported() const;
    inline bool is_lwp_supported() const;
    inline bool is_fma4_supported() const;
    inline bool is_tce_supported() const;
    inline bool is_nodeid_msr_supported() const;
    inline bool is_tbm_supported() const;
    inline bool is_topoext_supported() const;
    inline bool is_perfctr_core_supported() const;
    inline bool is_perfctr_nb_supported() const;
    inline bool is_dbx_supported() const;
    inline bool is_perftsc_supported() const;
    inline bool is_pcx_l2i_supported() const;

    // EAX=800000001: EDX

    //inline bool is_fpu_supported() const;
    //inline bool is_vme_supported() const;
    //inline bool is_de_supported() const;
    //inline bool is_pse_supported() const;
    //inline bool is_tsc_supported() const;
    //inline bool is_msr_supported() const;
    //inline bool is_pae_supported() const;
    //inline bool is_mce_supported() const;
    //inline bool is_cx8_supported() const;
    //inline bool is_apic_supported() const;
    inline bool is_syscall_supported() const;
    //inline bool is_mtrr_supported() const;
    //inline bool is_pge_supported() const;
    //inline bool is_mca_supported() const;
    //inline bool is_cmov_supported() const;
    //inline bool is_pat_supported() const;
    //inline bool is_pse36_supported() const;
    inline bool is_mp_supported() const;
    inline bool is_nx_supported() const;
    inline bool is_mmxext_supported() const;
    //inline bool is_mmx_supported() const;
    //inline bool is_fxsr_supported() const;
    inline bool is_fxsr_opt_supported() const;
    inline bool is_pdpe1gb_supported() const;
    inline bool is_rdtscp_supported() const;
    inline bool is_lm_supported() const;
    inline bool is_3dnowext_supported() const;
    inline bool is_3dnow_supported() const;

    std::string processor_brand_id() const { return processor_brand_id_; }

private:
    std::uint32_t highest_function_parameter_ {};
    char manufacturer_id_[13] {};
    std::bitset<32> f1ECX_ {};  ///< feature bits (0x00000001) ECX
    std::bitset<32> f1EDX_ {};  ///< feature bits (0x00000001) EDX
    std::bitset<32> f7EBX_ {};  ///< extended feature bits (0x00000007) EBX
    std::bitset<32> f7ECX_ {};  ///< extended feature bits (0x00000007) ECX
    std::bitset<32> f7EDX_ {};  ///< extended feature bits (0x00000007) EDX
    std::bitset<32> e1ECX_ {};  ///< extended feature bits (0x80000001) ECX
    std::bitset<32> e1EDX_ {};  ///< extended feature bits (0x80000001) EDX
    std::uint32_t highest_extended_function_parameter_ {};
    char processor_brand_id_[49] {};
};

inline cpuid_report::cpuid_report()
{
    // CPUID
    //         input: EAX, [ECX]
    //         output: EAX, EBX, ECX, EDX
    std::array<std::uint32_t, 4> cpuid_output_buffer {};
    auto &EAX = cpuid_output_buffer[0];
    auto &EBX = cpuid_output_buffer[1];
    auto &ECX = cpuid_output_buffer[2];
    auto &EDX = cpuid_output_buffer[3];

    // EAX=0x00000000: Highest Function Parameter and Manufacturer ID String
    //         EAX: Highest Function Parameter
    //         EBX, EDX, ECX: Manufacturer ID
    __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), 0x00000000u);
    highest_function_parameter_ = EAX;
    *reinterpret_cast<std::uint32_t*>(manufacturer_id_) = EBX;
    *reinterpret_cast<std::uint32_t*>(manufacturer_id_ + 4) = EDX;
    *reinterpret_cast<std::uint32_t*>(manufacturer_id_ + 8) = ECX;
    manufacturer_id_[12] = '\0';

    // EAX=0x00000001: Processor Info and Feature Bits
    if (0x00000001u <= highest_function_parameter_) {
        __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), 0x00000001u);
        f1ECX_ = ECX;
        f1EDX_ = EDX;
    }

    // EAX=0x00000002: Cache and TLB Descriptor information

    // EAX=0x00000003: Processor Serial Number

    // EAX=0x00000004,
    // EAX=0x0000000B: Intel thread/core and cache topology

    // EAX=0x00000007, ECX=0x00000000: Extended Feature Bits
    if (0x00000007u <= highest_function_parameter_) {
        __cpuidex(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), 0x00000007u, 0x00000000u);
        f7EBX_ = EBX;
        f7ECX_ = ECX;
        f7EDX_ = EDX;
    }

    // EAX=0x80000000: Highest Extended Function Parameter
    __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), static_cast<int>(0x80000000u));
    highest_extended_function_parameter_ = EAX;

    // EAX=0x80000001: Extended Feature Bits
    if (0x80000001u <= highest_extended_function_parameter_) {
        __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), static_cast<int>(0x80000001u));
        e1ECX_ = ECX;
        e1EDX_ = EDX;
    }

    // EAX=0x80000002,
    // EAX=0x80000003,
    // EAX=0x80000004: Processor Brand String
    if (0x80000004u <= highest_extended_function_parameter_) {
        __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), static_cast<int>(0x80000002u));
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_) = EAX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 4) = EBX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 8) = ECX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 12) = EDX;
        __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), static_cast<int>(0x80000003u));
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 16) = EAX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 20) = EBX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 24) = ECX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 28) = EDX;
        __cpuid(reinterpret_cast<std::int32_t *>(cpuid_output_buffer.data()), static_cast<int>(0x80000004u));
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 32) = EAX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 36) = EBX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 40) = ECX;
        *reinterpret_cast<std::uint32_t*>(processor_brand_id_ + 44) = EDX;
        processor_brand_id_[48] = '\0';
    }

    // EAX=0x80000005: L1 Cache and TLB Identifiers

    // EAX=0x80000006: Extended L2 Cache Features

    // EAX=0x80000007: Advanced Power Management Information

    // EAX=0x80000008: Virtual and Physical address Sizes

    // EAX=0x8FFFFFFF: AMD Easter Egg
}

inline bool cpuid_report::is_manufactured_by_amd() const
{
    return std::strcmp(manufacturer_id_, "AMDisbetter!") == 0
        || std::strcmp(manufacturer_id_, "AuthenticAMD") == 0;
}
inline bool cpuid_report::is_manufactured_by_centaur() const
{
    return std::strcmp(manufacturer_id_, "CentaurHauls") == 0;
}
inline bool cpuid_report::is_manufactured_by_cyrix() const
{
    return std::strcmp(manufacturer_id_, "CyrixInstead") == 0;
}
inline bool cpuid_report::is_manufactured_by_hygon() const
{
    return std::strcmp(manufacturer_id_, "HygonGenuine") == 0;
}
inline bool cpuid_report::is_manufactured_by_intel() const
{
    return std::strcmp(manufacturer_id_, "GenuineIntel") == 0;
}
inline bool cpuid_report::is_manufactured_by_transmeta() const
{
    return std::strcmp(manufacturer_id_, "TransmetaCPU") == 0
        || std::strcmp(manufacturer_id_, "GenuineTMx86") == 0;
}
inline bool cpuid_report::is_manufactured_by_nsc() const
{
    return std::strcmp(manufacturer_id_, "Geode by NSC") == 0;
}
inline bool cpuid_report::is_manufactured_by_nexgen() const
{
    return std::strcmp(manufacturer_id_, "NexGenDriven") == 0;
}
inline bool cpuid_report::is_manufactured_by_rise() const
{
    return std::strcmp(manufacturer_id_, "RiseRiseRise") == 0;
}
inline bool cpuid_report::is_manufactured_by_sis() const
{
    return std::strcmp(manufacturer_id_, "SiS SiS SiS ") == 0;
}
inline bool cpuid_report::is_manufactured_by_umc() const
{
    return std::strcmp(manufacturer_id_, "UMC UMC UMC ") == 0;
}
inline bool cpuid_report::is_manufactured_by_via() const
{
    return std::strcmp(manufacturer_id_, "VIA VIA VIA ") == 0;
}
inline bool cpuid_report::is_manufactured_by_vortex() const
{
    return std::strcmp(manufacturer_id_, "Vortex86 SoC") == 0;
}

inline bool cpuid_report::is_sse3_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[0];
}
inline bool cpuid_report::is_pclmulqdq_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[1];
}
inline bool cpuid_report::is_dtes64_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[2];
}
inline bool cpuid_report::is_monitor_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[3];
}
inline bool cpuid_report::is_ds_cpl_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[4];
}
inline bool cpuid_report::is_vmx_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[5];
}
inline bool cpuid_report::is_smx_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[6];
}
inline bool cpuid_report::is_est_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[7];
}
inline bool cpuid_report::is_tm2_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[8];
}
inline bool cpuid_report::is_ssse3_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[9];
}
inline bool cpuid_report::is_cnxt_id_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[10];
}
inline bool cpuid_report::is_sdbg_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[11];
}
inline bool cpuid_report::is_fma_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[12];
}
inline bool cpuid_report::is_cx16_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[13];
}
inline bool cpuid_report::is_xtpr_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[14];
}
inline bool cpuid_report::is_pdcm_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[15];
}
inline bool cpuid_report::is_pcid_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[17];
}
inline bool cpuid_report::is_dca_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[18];
}
inline bool cpuid_report::is_sse4_1_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[19];
}
inline bool cpuid_report::is_sse4_2_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[20];
}
inline bool cpuid_report::is_x2apic_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[21];
}
inline bool cpuid_report::is_movbe_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[22];
}
inline bool cpuid_report::is_popcnt_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[23];
}
inline bool cpuid_report::is_tsc_deadline_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[24];
}
inline bool cpuid_report::is_aes_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[25];
}
inline bool cpuid_report::is_xsave_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[26];
}
inline bool cpuid_report::is_osxsave_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[27];
}
inline bool cpuid_report::is_avx_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[28];
}
inline bool cpuid_report::is_f16c_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[29];
}
inline bool cpuid_report::is_rdrnd_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[30];
}
inline bool cpuid_report::is_hypervisor_supported() const
{
    return is_manufactured_by_intel() && f1ECX_[31];
}

inline bool cpuid_report::is_fpu_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[0]
        || is_manufactured_by_amd() && e1EDX_[0];
}
inline bool cpuid_report::is_vme_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[1]
        || is_manufactured_by_amd() && e1EDX_[1];
}
inline bool cpuid_report::is_de_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[2]
        || is_manufactured_by_amd() && e1EDX_[2];
}
inline bool cpuid_report::is_pse_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[3]
        || is_manufactured_by_amd() && e1EDX_[3];
}
inline bool cpuid_report::is_tsc_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[4]
        || is_manufactured_by_amd() && e1EDX_[4];
}
inline bool cpuid_report::is_msr_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[5]
        || is_manufactured_by_amd() && e1EDX_[5];
}
inline bool cpuid_report::is_pae_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[6]
        || is_manufactured_by_amd() && e1EDX_[6];
}
inline bool cpuid_report::is_mce_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[7]
        || is_manufactured_by_amd() && e1EDX_[7];
}
inline bool cpuid_report::is_cx8_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[8]
        || is_manufactured_by_amd() && e1EDX_[8];
}
inline bool cpuid_report::is_apic_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[9]
        || is_manufactured_by_amd() && e1EDX_[9];
}
inline bool cpuid_report::is_sep_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[11];
}
inline bool cpuid_report::is_mtrr_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[12]
        || is_manufactured_by_amd() && e1EDX_[12];
}
inline bool cpuid_report::is_pge_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[13]
        || is_manufactured_by_amd() && e1EDX_[13];
}
inline bool cpuid_report::is_mca_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[14]
        || is_manufactured_by_amd() && e1EDX_[14];
}
inline bool cpuid_report::is_cmov_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[15]
        || is_manufactured_by_amd() && e1EDX_[15];
}
inline bool cpuid_report::is_pat_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[16]
        || is_manufactured_by_amd() && e1EDX_[16];
}
inline bool cpuid_report::is_pse36_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[17]
        || is_manufactured_by_amd() && e1EDX_[17];
}
inline bool cpuid_report::is_psn_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[18];
}
inline bool cpuid_report::is_clfsh_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[19];
}
inline bool cpuid_report::is_ds_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[21];
}
inline bool cpuid_report::is_acpi_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[22];
}
inline bool cpuid_report::is_mmx_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[23]
        || is_manufactured_by_amd() && e1EDX_[23];
}
inline bool cpuid_report::is_fxsr_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[24]
        || is_manufactured_by_amd() && e1EDX_[14];
}
inline bool cpuid_report::is_sse_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[25];
}
inline bool cpuid_report::is_sse2_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[26];
}
inline bool cpuid_report::is_ss_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[27];
}
inline bool cpuid_report::is_htt_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[28];
}
inline bool cpuid_report::is_tm_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[29];
}
inline bool cpuid_report::is_ia64_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[30];
}
inline bool cpuid_report::is_pbe_supported() const
{
    return is_manufactured_by_intel() && f1EDX_[31];
}

inline bool cpuid_report::is_fsgsbase_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[0];
}
inline bool cpuid_report::is_sgx_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[2];
}
inline bool cpuid_report::is_bmi1_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[3];
}
inline bool cpuid_report::is_hle_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[4];
}
inline bool cpuid_report::is_avx2_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[5];
}
inline bool cpuid_report::is_smep_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[7];
}
inline bool cpuid_report::is_bmi2_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[8];
}
inline bool cpuid_report::is_erms_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[9];
}
inline bool cpuid_report::is_invpcid_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[10];
}
inline bool cpuid_report::is_rtm_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[11];
}
inline bool cpuid_report::is_pqm_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[12];
}
inline bool cpuid_report::is_mpx_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[14];
}
inline bool cpuid_report::is_pqe_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[15];
}
inline bool cpuid_report::is_avx512_f_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[16];
}
inline bool cpuid_report::is_avx512_dq_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[17];
}
inline bool cpuid_report::is_rdseed_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[18];
}
inline bool cpuid_report::is_adx_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[19];
}
inline bool cpuid_report::is_smap_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[20];
}
inline bool cpuid_report::is_avx512_ifma_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[21];
}
inline bool cpuid_report::is_pcommit_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[22];
}
inline bool cpuid_report::is_clflushopt_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[23];
}
inline bool cpuid_report::is_clwb_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[24];
}
inline bool cpuid_report::is_intel_pt_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[25];
}
inline bool cpuid_report::is_avx512_pf_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[26];
}
inline bool cpuid_report::is_avx512_er_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[27];
}
inline bool cpuid_report::is_avx512_cd_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[28];
}
inline bool cpuid_report::is_sha_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[29];
}
inline bool cpuid_report::is_avx512_bw_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[30];
}
inline bool cpuid_report::is_avx512_vl_supported() const
{
    return is_manufactured_by_intel() && f7EBX_[31];
}

inline bool cpuid_report::is_prefetchwt1_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[0];
}
inline bool cpuid_report::is_avx512_vbmi_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[1];
}
inline bool cpuid_report::is_umip_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[2];
}
inline bool cpuid_report::is_pku_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[3];
}
inline bool cpuid_report::is_ospke_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[4];
}
inline bool cpuid_report::is_waitpkg_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[5];
}
inline bool cpuid_report::is_avx512_vbmi2_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[6];
}
inline bool cpuid_report::is_shstk_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[7];
}
inline bool cpuid_report::is_gfni_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[8];
}
inline bool cpuid_report::is_vaes_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[9];
}
inline bool cpuid_report::is_vpclmulqdq_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[10];
}
inline bool cpuid_report::is_avx512_vnni_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[11];
}
inline bool cpuid_report::is_avx512_bitalg_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[12];
}
inline bool cpuid_report::is_avx512_vpopcntdq_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[14];
}
inline bool cpuid_report::is_mawau_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[17] && f7ECX_[18] && f7ECX_[19] && f7ECX_[20] && f7ECX_[21];
}
inline bool cpuid_report::is_rdpid_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[22];
}
inline bool cpuid_report::is_cldemote_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[25];
}
inline bool cpuid_report::is_movdir_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[27];
}
inline bool cpuid_report::is_movdir64b_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[28];
}
inline bool cpuid_report::is_sgx_lc_supported() const
{
    return is_manufactured_by_intel() && f7ECX_[30];
}

inline bool cpuid_report::is_avx512_4vnniw_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[2];
}
inline bool cpuid_report::is_avx512_4fmaps_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[3];
}
inline bool cpuid_report::is_fsrm_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[4];
}
inline bool cpuid_report::is_pconfig_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[18];
}
inline bool cpuid_report::is_ibt_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[20];
}
inline bool cpuid_report::is_spec_ctrl_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[26];
}
inline bool cpuid_report::is_stibp_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[27];
}
inline bool cpuid_report::is_capabilities_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[29];
}
inline bool cpuid_report::is_ssbd_supported() const
{
    return is_manufactured_by_intel() && f7EDX_[31];
}

inline bool cpuid_report::is_lahf_lm_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[0];
}
inline bool cpuid_report::is_cmp_legacy_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[1];
}
inline bool cpuid_report::is_svm_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[2];
}
inline bool cpuid_report::is_extapic_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[3];
}
inline bool cpuid_report::is_cr8_legacy_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[4];
}
inline bool cpuid_report::is_abm_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[5];
}
inline bool cpuid_report::is_sse4a_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[6];
}
inline bool cpuid_report::is_misalignsse_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[7];
}
inline bool cpuid_report::is_3dnowprefetch_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[8];
}
inline bool cpuid_report::is_osvw_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[9];
}
inline bool cpuid_report::is_ibs_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[10];
}
inline bool cpuid_report::is_xop_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[11];
}
inline bool cpuid_report::is_skinit_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[12];
}
inline bool cpuid_report::is_wdt_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[13];
}
inline bool cpuid_report::is_lwp_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[15];
}
inline bool cpuid_report::is_fma4_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[16];
}
inline bool cpuid_report::is_tce_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[17];
}
inline bool cpuid_report::is_nodeid_msr_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[19];
}
inline bool cpuid_report::is_tbm_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[21];
}
inline bool cpuid_report::is_topoext_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[22];
}
inline bool cpuid_report::is_perfctr_core_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[23];
}
inline bool cpuid_report::is_perfctr_nb_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[24];
}
inline bool cpuid_report::is_dbx_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[26];
}
inline bool cpuid_report::is_perftsc_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[27];
}
inline bool cpuid_report::is_pcx_l2i_supported() const
{
    return is_manufactured_by_amd() && e1ECX_[28];
}

inline bool cpuid_report::is_syscall_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[11];
}
inline bool cpuid_report::is_mp_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[19];
}
inline bool cpuid_report::is_nx_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[20];
}
inline bool cpuid_report::is_mmxext_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[22];
}
inline bool cpuid_report::is_fxsr_opt_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[25];
}
inline bool cpuid_report::is_pdpe1gb_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[26];
}
inline bool cpuid_report::is_rdtscp_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[27];
}
inline bool cpuid_report::is_lm_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[29];
}
inline bool cpuid_report::is_3dnowext_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[30];
}
inline bool cpuid_report::is_3dnow_supported() const
{
    return is_manufactured_by_amd() && e1EDX_[31];
}

}

#endif
