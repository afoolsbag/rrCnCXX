/// \copyright Unlicense

#pragma once
#ifndef RRASSEMBLY_RRCPUID_INL_
#define RRASSEMBLY_RRCPUID_INL_

#include "rrcpuid.hxx"

#include <array>

#include <intrin.h>  // intrinsics

namespace rrassembly {

inline cpuid_report::cpuid_report()
{
    // 0xA20F: CPUID
    //         input: EAX, [ECX]
    //         output: EAX, EBX, ECX, EDX
    std::array<std::uint32_t, 4> buf {};
    auto &EAX = buf[0];
    auto &EBX = buf[1];
    auto &ECX = buf[2];
    auto &EDX = buf[3];

    __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b00000000'00000000'00000000'00000000u));
    F0EAX = EAX;
    F0EBX = EBX;
    F0ECX = ECX;
    F0EDX = EDX;

    if (0b00000000'00000000'00000000'00000001u <= highest_function_leaf()) {
        __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b00000000'00000000'00000000'00000001u));
        F1ECX = ECX;
        F1EDX = EDX;
    }

    if (0b00000000'00000000'00000000'00000111u <= highest_function_leaf()) {
        __cpuidex(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b00000000'00000000'00000000'00000111u), static_cast<int>(0b00000000'00000000'00000000'00000000u));
        F7EBX = EBX;
        F7ECX = ECX;
        F7EDX = EDX;
    }

    __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b10000000'00000000'00000000'00000000u));
    E0EAX = EAX;

    if (0b10000000'00000000'00000000'00000001u <= highest_extended_function_leaf()) {
        __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b10000000'00000000'00000000'00000001u));
        E1ECX = ECX;
        E1EDX = EDX;
    }

    if (0b10000000'00000000'00000000'00000100u <= highest_extended_function_leaf()) {
        __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b10000000'00000000'00000000'00000010u));
        E2EAX = EAX;
        E2EBX = EBX;
        E2ECX = ECX;
        E2EDX = EDX;
        __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b10000000'00000000'00000000'00000011u));
        E3EAX = EAX;
        E3EBX = EBX;
        E3ECX = ECX;
        E3EDX = EDX;
        __cpuid(reinterpret_cast<std::int32_t *>(buf.data()), static_cast<int>(0b10000000'00000000'00000000'00000100u));
        E4EAX = EAX;
        E4EBX = EBX;
        E4ECX = ECX;
        E4EDX = EDX;
    }
}

inline uint32_t cpuid_report::highest_function_leaf() const { return F0EAX.to_ulong(); }

inline std::string cpuid_report::manufacturer_id() const
{
    char buf[13];
    *reinterpret_cast<std::uint32_t*>(buf) = F0EBX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 4) = F0EDX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 8) = F0ECX.to_ulong();
    buf[12] = '\0';
    return buf;
}

inline bool cpuid_report::is_sse3_supported() const noexcept { return F1ECX[0]; }
inline bool cpuid_report::is_pclmulqdq_supported() const noexcept { return F1ECX[1]; }
inline bool cpuid_report::is_dtes64_supported() const noexcept { return F1ECX[2]; }
inline bool cpuid_report::is_monitor_supported() const noexcept { return F1ECX[3]; }
inline bool cpuid_report::is_ds_cpl_supported() const noexcept { return F1ECX[4]; }
inline bool cpuid_report::is_vmx_supported() const noexcept { return F1ECX[5]; }
inline bool cpuid_report::is_smx_supported() const noexcept { return F1ECX[6]; }
inline bool cpuid_report::is_est_supported() const noexcept { return F1ECX[7]; }
inline bool cpuid_report::is_tm2_supported() const noexcept { return F1ECX[8]; }
inline bool cpuid_report::is_ssse3_supported() const noexcept { return F1ECX[9]; }
inline bool cpuid_report::is_cnxt_id_supported() const noexcept { return F1ECX[10]; }
inline bool cpuid_report::is_sdbg_supported() const noexcept { return F1ECX[11]; }
inline bool cpuid_report::is_fma_supported() const noexcept { return F1ECX[12]; }
inline bool cpuid_report::is_cx16_supported() const noexcept { return F1ECX[13]; }
inline bool cpuid_report::is_xtpr_supported() const noexcept { return F1ECX[14]; }
inline bool cpuid_report::is_pdcm_supported() const noexcept { return F1ECX[15]; }
inline bool cpuid_report::is_pcid_supported() const noexcept { return F1ECX[17]; }
inline bool cpuid_report::is_dca_supported() const noexcept { return F1ECX[18]; }
inline bool cpuid_report::is_sse4_1_supported() const noexcept { return F1ECX[19]; }
inline bool cpuid_report::is_sse4_2_supported() const noexcept { return F1ECX[20]; }
inline bool cpuid_report::is_x2apic_supported() const noexcept { return F1ECX[21]; }
inline bool cpuid_report::is_movbe_supported() const noexcept { return F1ECX[22]; }
inline bool cpuid_report::is_popcnt_supported() const noexcept { return F1ECX[23]; }
inline bool cpuid_report::is_tsc_deadline_supported() const noexcept { return F1ECX[24]; }
inline bool cpuid_report::is_aes_supported() const noexcept { return F1ECX[25]; }
inline bool cpuid_report::is_xsave_supported() const noexcept { return F1ECX[26]; }
inline bool cpuid_report::is_osxsave_supported() const noexcept { return F1ECX[27]; }
inline bool cpuid_report::is_avx_supported() const noexcept { return F1ECX[28]; }
inline bool cpuid_report::is_f16c_supported() const noexcept { return F1ECX[29]; }
inline bool cpuid_report::is_rdrnd_supported() const noexcept { return F1ECX[30]; }
inline bool cpuid_report::is_hypervisor_supported() const noexcept { return F1ECX[31]; }

inline bool cpuid_report::is_fpu_supported() const noexcept { return  F1EDX[0] || E1EDX[0]; }
inline bool cpuid_report::is_vme_supported() const noexcept { return F1EDX[1] || E1EDX[1]; }
inline bool cpuid_report::is_de_supported() const noexcept { return F1EDX[2] || E1EDX[2]; }
inline bool cpuid_report::is_pse_supported() const noexcept { return F1EDX[3] || E1EDX[3]; }
inline bool cpuid_report::is_tsc_supported() const noexcept { return F1EDX[4] || E1EDX[4]; }
inline bool cpuid_report::is_msr_supported() const noexcept { return F1EDX[5] || E1EDX[5]; }
inline bool cpuid_report::is_pae_supported() const noexcept { return F1EDX[6] || E1EDX[6]; }
inline bool cpuid_report::is_mce_supported() const noexcept { return F1EDX[7] || E1EDX[7]; }
inline bool cpuid_report::is_cx8_supported() const noexcept { return F1EDX[8] || E1EDX[8]; }
inline bool cpuid_report::is_apic_supported() const noexcept { return F1EDX[9] || E1EDX[9]; }
inline bool cpuid_report::is_sep_supported() const noexcept { return F1EDX[11]; }
inline bool cpuid_report::is_mtrr_supported() const noexcept { return F1EDX[12] || E1EDX[12]; }
inline bool cpuid_report::is_pge_supported() const noexcept { return F1EDX[13] || E1EDX[13]; }
inline bool cpuid_report::is_mca_supported() const noexcept { return F1EDX[14] || E1EDX[14]; }
inline bool cpuid_report::is_cmov_supported() const noexcept { return F1EDX[15] || E1EDX[15]; }
inline bool cpuid_report::is_pat_supported() const noexcept { return F1EDX[16] || E1EDX[16]; }
inline bool cpuid_report::is_pse36_supported() const noexcept { return F1EDX[17] || E1EDX[17]; }
inline bool cpuid_report::is_psn_supported() const noexcept { return F1EDX[18]; }
inline bool cpuid_report::is_clfsh_supported() const noexcept { return F1EDX[19]; }
inline bool cpuid_report::is_ds_supported() const noexcept { return F1EDX[21]; }
inline bool cpuid_report::is_acpi_supported() const noexcept { return F1EDX[22]; }
inline bool cpuid_report::is_mmx_supported() const noexcept { return F1EDX[23] || E1EDX[23]; }
inline bool cpuid_report::is_fxsr_supported() const noexcept { return F1EDX[24] || E1EDX[14]; }
inline bool cpuid_report::is_sse_supported() const noexcept { return F1EDX[25]; }
inline bool cpuid_report::is_sse2_supported() const noexcept { return F1EDX[26]; }
inline bool cpuid_report::is_ss_supported() const noexcept { return F1EDX[27]; }
inline bool cpuid_report::is_htt_supported() const noexcept { return F1EDX[28]; }
inline bool cpuid_report::is_tm_supported() const noexcept { return F1EDX[29]; }
inline bool cpuid_report::is_ia64_supported() const noexcept { return F1EDX[30]; }
inline bool cpuid_report::is_pbe_supported() const noexcept { return F1EDX[31]; }

inline bool cpuid_report::is_fsgsbase_supported() const noexcept { return F7EBX[0]; }
inline bool cpuid_report::is_sgx_supported() const noexcept { return F7EBX[2]; }
inline bool cpuid_report::is_bmi1_supported() const noexcept { return F7EBX[3]; }
inline bool cpuid_report::is_hle_supported() const noexcept { return F7EBX[4]; }
inline bool cpuid_report::is_avx2_supported() const noexcept { return F7EBX[5]; }
inline bool cpuid_report::is_smep_supported() const noexcept { return F7EBX[7]; }
inline bool cpuid_report::is_bmi2_supported() const noexcept { return F7EBX[8]; }
inline bool cpuid_report::is_erms_supported() const noexcept { return F7EBX[9]; }
inline bool cpuid_report::is_invpcid_supported() const noexcept { return F7EBX[10]; }
inline bool cpuid_report::is_rtm_supported() const noexcept { return F7EBX[11]; }
inline bool cpuid_report::is_pqm_supported() const noexcept { return F7EBX[12]; }
inline bool cpuid_report::is_mpx_supported() const noexcept { return F7EBX[14]; }
inline bool cpuid_report::is_pqe_supported() const noexcept { return F7EBX[15]; }
inline bool cpuid_report::is_avx512_f_supported() const noexcept { return F7EBX[16]; }
inline bool cpuid_report::is_avx512_dq_supported() const noexcept { return F7EBX[17]; }
inline bool cpuid_report::is_rdseed_supported() const noexcept { return F7EBX[18]; }
inline bool cpuid_report::is_adx_supported() const noexcept { return F7EBX[19]; }
inline bool cpuid_report::is_smap_supported() const noexcept { return F7EBX[20]; }
inline bool cpuid_report::is_avx512_ifma_supported() const noexcept { return F7EBX[21]; }
inline bool cpuid_report::is_pcommit_supported() const noexcept { return F7EBX[22]; }
inline bool cpuid_report::is_clflushopt_supported() const noexcept { return F7EBX[23]; }
inline bool cpuid_report::is_clwb_supported() const noexcept { return F7EBX[24]; }
inline bool cpuid_report::is_intel_pt_supported() const noexcept { return F7EBX[25]; }
inline bool cpuid_report::is_avx512_pf_supported() const noexcept { return F7EBX[26]; }
inline bool cpuid_report::is_avx512_er_supported() const noexcept { return F7EBX[27]; }
inline bool cpuid_report::is_avx512_cd_supported() const noexcept { return F7EBX[28]; }
inline bool cpuid_report::is_sha_supported() const noexcept { return F7EBX[29]; }
inline bool cpuid_report::is_avx512_bw_supported() const noexcept { return F7EBX[30]; }
inline bool cpuid_report::is_avx512_vl_supported() const noexcept { return F7EBX[31]; }

inline bool cpuid_report::is_prefetchwt1_supported() const noexcept { return F7ECX[0]; }
inline bool cpuid_report::is_avx512_vbmi_supported() const noexcept { return F7ECX[1]; }
inline bool cpuid_report::is_umip_supported() const noexcept { return F7ECX[2]; }
inline bool cpuid_report::is_pku_supported() const noexcept { return F7ECX[3]; }
inline bool cpuid_report::is_ospke_supported() const noexcept { return F7ECX[4]; }
inline bool cpuid_report::is_waitpkg_supported() const noexcept { return F7ECX[5]; }
inline bool cpuid_report::is_avx512_vbmi2_supported() const noexcept { return F7ECX[6]; }
inline bool cpuid_report::is_shstk_supported() const noexcept { return F7ECX[7]; }
inline bool cpuid_report::is_gfni_supported() const noexcept { return F7ECX[8]; }
inline bool cpuid_report::is_vaes_supported() const noexcept { return F7ECX[9]; }
inline bool cpuid_report::is_vpclmulqdq_supported() const noexcept { return F7ECX[10]; }
inline bool cpuid_report::is_avx512_vnni_supported() const noexcept { return F7ECX[11]; }
inline bool cpuid_report::is_avx512_bitalg_supported() const noexcept { return F7ECX[12]; }
inline bool cpuid_report::is_avx512_vpopcntdq_supported() const noexcept { return F7ECX[14]; }
inline bool cpuid_report::is_mawau_supported() const noexcept { return F7ECX[17] && F7ECX[18] && F7ECX[19] && F7ECX[20] && F7ECX[21]; }
inline bool cpuid_report::is_rdpid_supported() const noexcept { return F7ECX[22]; }
inline bool cpuid_report::is_cldemote_supported() const noexcept { return F7ECX[25]; }
inline bool cpuid_report::is_movdir_supported() const noexcept { return F7ECX[27]; }
inline bool cpuid_report::is_movdir64b_supported() const noexcept { return F7ECX[28]; }
inline bool cpuid_report::is_sgx_lc_supported() const noexcept { return F7ECX[30]; }

inline bool cpuid_report::is_avx512_4vnniw_supported() const noexcept { return F7EDX[2]; }
inline bool cpuid_report::is_avx512_4fmaps_supported() const noexcept { return F7EDX[3]; }
inline bool cpuid_report::is_fsrm_supported() const noexcept { return F7EDX[4]; }
inline bool cpuid_report::is_pconfig_supported() const noexcept { return F7EDX[18]; }
inline bool cpuid_report::is_ibt_supported() const noexcept { return F7EDX[20]; }
inline bool cpuid_report::is_spec_ctrl_supported() const noexcept { return F7EDX[26]; }
inline bool cpuid_report::is_stibp_supported() const noexcept { return F7EDX[27]; }
inline bool cpuid_report::is_capabilities_supported() const noexcept { return F7EDX[29]; }
inline bool cpuid_report::is_ssbd_supported() const noexcept { return F7EDX[31]; }

inline uint32_t cpuid_report::highest_extended_function_leaf() const { return E0EAX.to_ulong(); }

inline bool cpuid_report::is_lahf_lm_supported() const noexcept { return E1ECX[0]; }
inline bool cpuid_report::is_cmp_legacy_supported() const noexcept { return E1ECX[1]; }
inline bool cpuid_report::is_svm_supported() const noexcept { return E1ECX[2]; }
inline bool cpuid_report::is_extapic_supported() const noexcept { return E1ECX[3]; }
inline bool cpuid_report::is_cr8_legacy_supported() const noexcept { return E1ECX[4]; }
inline bool cpuid_report::is_abm_supported() const noexcept { return E1ECX[5]; }
inline bool cpuid_report::is_sse4a_supported() const noexcept { return E1ECX[6]; }
inline bool cpuid_report::is_misalignsse_supported() const noexcept { return E1ECX[7]; }
inline bool cpuid_report::is_3dnowprefetch_supported() const noexcept { return E1ECX[8]; }
inline bool cpuid_report::is_osvw_supported() const noexcept { return E1ECX[9]; }
inline bool cpuid_report::is_ibs_supported() const noexcept { return E1ECX[10]; }
inline bool cpuid_report::is_xop_supported() const noexcept { return E1ECX[11]; }
inline bool cpuid_report::is_skinit_supported() const noexcept { return E1ECX[12]; }
inline bool cpuid_report::is_wdt_supported() const noexcept { return E1ECX[13]; }
inline bool cpuid_report::is_lwp_supported() const noexcept { return E1ECX[15]; }
inline bool cpuid_report::is_fma4_supported() const noexcept { return E1ECX[16]; }
inline bool cpuid_report::is_tce_supported() const noexcept { return E1ECX[17]; }
inline bool cpuid_report::is_nodeid_msr_supported() const noexcept { return E1ECX[19]; }
inline bool cpuid_report::is_tbm_supported() const noexcept { return E1ECX[21]; }
inline bool cpuid_report::is_topoext_supported() const noexcept { return E1ECX[22]; }
inline bool cpuid_report::is_perfctr_core_supported() const noexcept { return E1ECX[23]; }
inline bool cpuid_report::is_perfctr_nb_supported() const noexcept { return E1ECX[24]; }
inline bool cpuid_report::is_dbx_supported() const noexcept { return E1ECX[26]; }
inline bool cpuid_report::is_perftsc_supported() const noexcept { return E1ECX[27]; }
inline bool cpuid_report::is_pcx_l2i_supported() const noexcept { return E1ECX[28]; }

inline bool cpuid_report::is_syscall_supported() const noexcept { return E1EDX[11]; }
inline bool cpuid_report::is_mp_supported() const noexcept { return E1EDX[19]; }
inline bool cpuid_report::is_nx_supported() const noexcept { return E1EDX[20]; }
inline bool cpuid_report::is_mmxext_supported() const noexcept { return E1EDX[22]; }
inline bool cpuid_report::is_fxsr_opt_supported() const noexcept { return E1EDX[25]; }
inline bool cpuid_report::is_pdpe1gb_supported() const noexcept { return E1EDX[26]; }
inline bool cpuid_report::is_rdtscp_supported() const noexcept { return E1EDX[27]; }
inline bool cpuid_report::is_lm_supported() const noexcept { return E1EDX[29]; }
inline bool cpuid_report::is_3dnowext_supported() const noexcept { return E1EDX[30]; }
inline bool cpuid_report::is_3dnow_supported() const noexcept { return E1EDX[31]; }

inline std::string cpuid_report::processor_brand() const
{
    char buf[49];
    *reinterpret_cast<std::uint32_t*>(buf) = E2EAX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 4) = E2EBX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 8) = E2ECX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 12) = E2EDX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 16) = E3EAX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 20) = E3EBX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 24) = E3ECX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 28) = E3EDX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 32) = E4EAX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 36) = E4EBX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 40) = E4ECX.to_ulong();
    *reinterpret_cast<std::uint32_t*>(buf + 44) = E4EDX.to_ulong();
    buf[48] = '\0';
    return buf;
}

}

#endif
