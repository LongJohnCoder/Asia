//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _MACHINE_CHECK_H
#define _MACHINE_CHECK_H

#include "Tiano.h"
#include "CpuIa32.h"


#define X86_FEATURE_MCE					0x80		 /* Machine Check Exception */
#define X86_FEATURE_MCA					0x4000		 /* Machine Check Architecture */
#define X86_CR4_MCE						0x40		 /* Machine check enable */

/* MCG_CAP register defines */
#define MCG_BANKCNT_MASK				0xFF         /* Number of Banks */
#define MCG_CTL_P						(1ULL<<8)    /* MCG_CTL register available */
#define MCG_EXT_P						(1ULL<<9)    /* Extended registers available */
#define MCG_CMCI_P						(1ULL<<10)   /* CMCI supported */
#define MCG_EXT_CNT_MASK				0xFF0000     /* Number of Extended registers */
#define MCG_EXT_CNT_SHIFT				16
#define MCG_EXT_CNT(c)					(((c) & MCG_EXT_CNT_MASK) >> MCG_EXT_CNT_SHIFT)
#define MCG_SER_P						(1ULL<<24)   /* MCA recovery/new status bits */
#define MCG_EMC_P						(1ULL<<25)   /* Capabilities for Firmware First signaling */
#define MCG_ELOG_P						(1ULL<<26)   /* Extended error log supported */

#define MSR_IA32_MCG_CAP				0x179
#define MSR_IA32_MC0_CTL				0x400
#define MSR_IA32_MC0_STATUS				0x401
#define MSR_IA32_MC0_ADDR				0x402
#define MSR_IA32_MC0_MISC				0x403
#define MSR_IA32_MC0_CTL2				0x280


#define MSR_IA32_MCx_CTL(x)				(MSR_IA32_MC0_CTL + 4*(x))
#define MSR_IA32_MCx_STATUS(x)			(MSR_IA32_MC0_STATUS + 4*(x))
#define MSR_IA32_MCx_ADDR(x)			(MSR_IA32_MC0_ADDR + 4*(x))
#define MSR_IA32_MCx_MISC(x)			(MSR_IA32_MC0_MISC + 4*(x))
#define MSR_IA32_MCx_CTL2(x)			(MSR_IA32_MC0_CTL2 + (x))

/* CTL2 register defines */
#define MCI_CTL2_CMCI_EN				(1ULL << 30)
#define MCI_CTL2_CMCI_THRESHOLD_MASK	0x7FFFULL
#define	CMCI_THRESHOLD					0x4000


#define BJ_MCA_ZX_CTRL					 	0x1612
#define BJ_MCA_ZX_CTRL2_MSR					0x1617
#define BJ_MCA_ZX_L2_ERROR_THRESHOLD_MSR	0x1615
#define BJ_MCA_ZX_L2_ERROR_THRESHOLD_MASK	0x7FFF

#define CRMCA_MMIO_BASE_LOCK			(1ULL<<28)
#define CRMCA_MMIO_BASE_MASK			0xFFFFFFF

#define CRMCA_MMIO_BASE					0xFE020000
#define CRMCA_MMIO_MASTER_BASE			0xFEB20000
#define CRMCA_MMIO_SLAVE_BASE			0xFEBA0000

EFI_STATUS MachineCheckInitialize(BOOLEAN MachineCheck);


BOOLEAN IsMceSupport();

#endif
