/*
 * Copyright (C) 2011 Motorola Mobility, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307, USA
 */

#ifndef __LINUX_POWER_MMI_BATTERY_H__
#define __LINUX_POWER_MMI_BATTERY_H__

#define CPYRGHT_STRING_PART_1 "COPR"
#define CPYRGHT_STRING_PART_2 "MOTOROLA E.P CHARGE ONLY"
/* Used for converting BRT data */
#define SCALE_RESTORE		(1024)
#define SCALE_TO_MV		(1000)
#define CHRG_RESOLUTION		((3921 * SCALE_RESTORE) / 1000)
#define BATTP_RESOLUTION	((16675 * SCALE_RESTORE) / 1000)
#define BATTERY_VOLTAGE		(16702) /*((2300 * 1000000) / 255 / 540)*/
#define BATTERY_V_ADDER		(1260)
#define BPLUS_VOLTAGE		(18790) /*((2300 * 1000000) /255 /480)*/
#define BPLUS_V_ADDER		(1660)
#define HYSTERESIS_VLTG		((16675 * SCALE_RESTORE) / 1000)
#define ADC_REFERENCE		2300
#define ADC_OFFSET		2400
#define VLT_ROM_OFFSET_100_PERC	4000
#define C5_VLT_LVL_OFFSET	712
#define OLD_EPROM_CELL_ID	0x0501

enum {
	MMI_BATTERY_INVALID,
	MMI_BATTERY_VALID,
	MMI_BATTERY_UNKNOWN = 0xFF,
};

/*-----------------------------------------------------------------------------
 * DESCRIPTION:
 * This enumeration indexes the data received from the ROM of a Motorola
 * battery.
 */
enum {
	/* Begin Page 1 */
	ROM_DATA_PAGE_1_BGN,
	ROM_DATA_BYTE_00 = ROM_DATA_PAGE_1_BGN,
	ROM_DATA_BYTE_01,
	ROM_DATA_BYTE_02,
	ROM_DATA_BYTE_03,
	ROM_DATA_BYTE_04,
	ROM_DATA_BYTE_05,
	ROM_DATA_BYTE_06,
	ROM_DATA_BYTE_07,
	ROM_DATA_BYTE_08,
	ROM_DATA_BYTE_09,
	ROM_DATA_BYTE_0A,
	ROM_DATA_BYTE_0B,
	ROM_DATA_BYTE_0C,
	ROM_DATA_BYTE_0D,
	ROM_DATA_BYTE_0E,
	ROM_DATA_BYTE_0F,
	ROM_DATA_BYTE_10,
	ROM_DATA_BYTE_11,
	ROM_DATA_BYTE_12,
	ROM_DATA_BYTE_13,
	ROM_DATA_BYTE_14,
	ROM_DATA_BYTE_15,
	ROM_DATA_BYTE_16,
	ROM_DATA_BYTE_17,
	ROM_DATA_BYTE_18,
	ROM_DATA_BYTE_19,
	ROM_DATA_BYTE_1A,
	ROM_DATA_BYTE_1B,
	ROM_DATA_BYTE_1C,
	ROM_DATA_BYTE_1D,
	ROM_DATA_BYTE_1E,
	ROM_DATA_BYTE_1F,
	ROM_DATA_PAGE_1_END = ROM_DATA_BYTE_1F,
	/* End Page 1 */

	/* Begin Page 2 */
	ROM_DATA_PAGE_2_BGN,
	ROM_DATA_PAGE_2_CHKSM = ROM_DATA_PAGE_2_BGN,
	ROM_DATA_DC_IMPEDANCE,

	/* Common Data */
	ROM_DATA_CMN_BGN,
	ROM_DATA_CMN_BATT_CPCTY = ROM_DATA_CMN_BGN,
	ROM_DATA_CMN_RPD_TMP_MAX,
	ROM_DATA_CMN_RPD_TMP_MIN,
	ROM_DATA_CMN_TMP_COMP_OFFSET_HOT,
	ROM_DATA_CMN_TMP_COMP_OFFSET_CLD,
	ROM_DATA_CMN_RPD_CHRG_RATE_FST,
	ROM_DATA_CMN_RPD_CHRG_TM_LIM_FST,
	ROM_DATA_CMN_RPD_CHRG_RATE_MID,
	ROM_DATA_CMN_RPD_CHRG_TM_LIM_MID,
	ROM_DATA_CMN_CELL_ID_MSB,
	ROM_DATA_CMN_CELL_ID_LSB,
	ROM_DATA_CMN_MAINT_CHRG_RATE,
	ROM_DATA_CMN_DELTA_VLT_RSTRT_FST,
	ROM_DATA_CMN_MAIN_AUX_SEL,
	ROM_DATA_CMN_EPROM_VER,
	ROM_DATA_CMN_BATT_TYPE,
	ROM_DATA_CMN_END = ROM_DATA_CMN_BATT_TYPE,
	/* End Common Data */

	/* Begin CDMA / AMPS Data */
	ROM_DATA_CDMA_AMPS_BGN,
	ROM_DATA_CDMA_AMPS_VLT_MAX = ROM_DATA_CDMA_AMPS_BGN,
	ROM_DATA_CDMA_AMPS_VLT_MIN,
	ROM_DATA_CDMA_AMPS_CHRG_GGL1,
	ROM_DATA_CDMA_AMPS_CHRG_GGL2,
	ROM_DATA_CDMA_AMPS_CHRG_GGL3,
	ROM_DATA_CDMA_AMPS_DSCHRG_SU_OFF_VLT_DKY,
	ROM_DATA_CDMA_AMPS_DSCHRG_GGL1_DKY,
	ROM_DATA_CDMA_AMPS_DSCHRG_GGL2_DKY,
	ROM_DATA_CDMA_AMPS_DSCHRG_GGL3_DKY,
	ROM_DATA_CDMA_AMPS_DSCHRG_SU_OFF_VLT_KEY,
	ROM_DATA_CDMA_AMPS_DSCHRG_GGL1_KEY,
	ROM_DATA_CDMA_AMPS_DSCHRG_GGL2_KEY,
	ROM_DATA_CDMA_AMPS_DSCHRG_GGL3_KEY,
	ROM_DATA_CDMA_AMPS_DSCHRG_HYSTER_VLT,
	ROM_DATA_CDMA_AMPS_END = ROM_DATA_CDMA_AMPS_DSCHRG_HYSTER_VLT,
	/* End CDMA / AMPS Data */

	ROM_DATA_PAGE_2_END = ROM_DATA_CDMA_AMPS_DSCHRG_HYSTER_VLT,
	/* End Page 2 */

	/* Begin Page 3 */
	ROM_DATA_PAGE_3_BGN,
	ROM_DATA_PAGE_3_CHKSM = ROM_DATA_PAGE_3_BGN,

	/* Begin GSM / TDMA Data */
	ROM_DATA_GSM_TDMA_BGN,
	ROM_DATA_GSM_TDMA_VLT_MAX = ROM_DATA_GSM_TDMA_BGN,
	ROM_DATA_GSM_TDMA_VLT_MIN,
	ROM_DATA_GSM_TDMA_CHRG_GGL1,
	ROM_DATA_GSM_TDMA_CHRG_GGL2,
	ROM_DATA_GSM_TDMA_CHRG_GGL3,
	ROM_DATA_GSM_TDMA_DSCHRG_SU_OFF_VLT_DKY,
	ROM_DATA_GSM_TDMA_DSCHRG_GGL1_DKY,
	ROM_DATA_GSM_TDMA_DSCHRG_GGL2_DKY,
	ROM_DATA_GSM_TDMA_DSCHRG_GGL3_DKY,
	ROM_DATA_GSM_TDMA_DSCHRG_SU_OFF_VLT_KEY,
	ROM_DATA_GSM_TDMA_DSCHRG_GGL1_KEY,
	ROM_DATA_GSM_TDMA_DSCHRG_GGL2_KEY,
	ROM_DATA_GSM_TDMA_DSCHRG_GGL3_KEY,
	ROM_DATA_GSM_TDMA_DSCHRG_HYSTER_VLT,
	ROM_DATA_GSM_TDMA_END = ROM_DATA_GSM_TDMA_DSCHRG_HYSTER_VLT,
	/* End GSM / TDMA Data */

	ROM_DATA_BYTE_4F_FREE,

	/* Begin iDEN Data */
	ROM_DATA_IDEN_BGN,
	ROM_DATA_IDEN_VLT_MAX = ROM_DATA_IDEN_BGN,
	ROM_DATA_IDEN_VLT_MIN,
	ROM_DATA_IDEN_CHRG_GGL1,
	ROM_DATA_IDEN_CHRG_GGL2,
	ROM_DATA_IDEN_CHRG_GGL3,
	ROM_DATA_IDEN_DSCHRG_SU_OFF_VLT_DKY,
	ROM_DATA_IDEN_DSCHRG_GGL1_DKY,
	ROM_DATA_IDEN_DSCHRG_GGL2_DKY,
	ROM_DATA_IDEN_DSCHRG_GGL3_DKY,
	ROM_DATA_IDEN_DSCHRG_SU_OFF_VLT_KEY,
	ROM_DATA_IDEN_DSCHRG_GGL1_KEY,
	ROM_DATA_IDEN_DSCHRG_GGL2_KEY,
	ROM_DATA_IDEN_DSCHRG_GGL3_KEY,
	ROM_DATA_IDEN_DSCHRG_HYSTER_VLT,
	ROM_DATA_IDEN_END = ROM_DATA_IDEN_DSCHRG_HYSTER_VLT,
	/* End iDEN Data */

	ROM_DATA_BYTE_5E_FREE,
	ROM_DATA_BYTE_5F_FREE,
	ROM_DATA_PAGE_3_END = ROM_DATA_BYTE_5F_FREE,
	/* End Page 3 */

	/* Begin Page 4 */
	ROM_DATA_PAGE_4_BGN,

	/* Begin Copyright Part 1 "COPR" */
	ROM_DATA_CPYRGHT_PART_1_BGN = ROM_DATA_PAGE_4_BGN,
	ROM_DATA_BYTE_60 = ROM_DATA_PAGE_4_BGN,
	ROM_DATA_BYTE_61,
	ROM_DATA_BYTE_62,
	ROM_DATA_BYTE_63,
	ROM_DATA_CPYRGHT_PART_1_END = ROM_DATA_BYTE_63,
	/* End Copyright Part 1 "COPR" */

	/* Begin Copyright Date - this data is ignored */
	ROM_DATA_BYTE_64,
	ROM_DATA_BYTE_65,
	ROM_DATA_BYTE_66,
	ROM_DATA_BYTE_67,
	/* End Copyright Date - this data is ignored */

	/* Begin Copyright Part 2 "MOTOROLA E.P CHARGE ONLY" */
	ROM_DATA_CPYRGHT_PART_2_BGN,
	ROM_DATA_BYTE_68 = ROM_DATA_CPYRGHT_PART_2_BGN,
	ROM_DATA_BYTE_69,
	ROM_DATA_BYTE_6A,
	ROM_DATA_BYTE_6B,
	ROM_DATA_BYTE_6C,
	ROM_DATA_BYTE_6D,
	ROM_DATA_BYTE_6E,
	ROM_DATA_BYTE_6F,
	ROM_DATA_BYTE_70,
	ROM_DATA_BYTE_71,
	ROM_DATA_BYTE_72,
	ROM_DATA_BYTE_73,
	ROM_DATA_BYTE_74,
	ROM_DATA_BYTE_75,
	ROM_DATA_BYTE_76,
	ROM_DATA_BYTE_77,
	ROM_DATA_BYTE_78,
	ROM_DATA_BYTE_79,
	ROM_DATA_BYTE_7A,
	ROM_DATA_BYTE_7B,
	ROM_DATA_BYTE_7C,
	ROM_DATA_BYTE_7D,
	ROM_DATA_BYTE_7E,
	ROM_DATA_BYTE_7F,
	ROM_DATA_CPYRGHT_PART_2_END = ROM_DATA_BYTE_7F,
	/* End Copyright Part 2 "MOTOROLA E.P CHARGE ONLY" */

	ROM_DATA_PAGE_4_END = ROM_DATA_BYTE_7F,
	/* End Page 4 */

	/* Begin Page 5 */
	ROM_DATA_PAGE_5_BGN,
	ROM_DATA_PAGE_5_CHKSM = ROM_DATA_PAGE_5_BGN,
	ROM_DATA_C5_100,
	ROM_DATA_C5_95,
	ROM_DATA_C5_90,
	ROM_DATA_C5_85,
	ROM_DATA_C5_80,
	ROM_DATA_C5_75,
	ROM_DATA_C5_70,
	ROM_DATA_C5_65,
	ROM_DATA_C5_60,
	ROM_DATA_C5_55,
	ROM_DATA_C5_50,
	ROM_DATA_C5_45,
	ROM_DATA_C5_40,
	ROM_DATA_C5_35,
	ROM_DATA_C5_30,
	ROM_DATA_C5_25,
	ROM_DATA_C5_20,
	ROM_DATA_C5_15,
	ROM_DATA_C5_10,
	ROM_DATA_C5_05,
	ROM_DATA_C5_04,
	ROM_DATA_C5_03,
	ROM_DATA_C5_02,
	ROM_DATA_C5_01,
	ROM_DATA_C5_00,
	ROM_DATA_HV_CHRG_RATE,
	ROM_DATA_HV_TRANS_VOLTAGE,
	ROM_DATA_CYCLE_AGE_100,
	ROM_DATA_CYCLE_AGE_250,
	ROM_DATA_CYCLE_AGE_400,
	ROM_DATA_CYCLE_AGE_500,
	ROM_DATA_PAGE_5_END = ROM_DATA_CYCLE_AGE_500,
	/* End Page 5 */

	/* Begin Page 6 */
	ROM_DATA_PAGE_6_BGN,
	ROM_DATA_DC_IMPD_70_0C_0 = ROM_DATA_PAGE_6_BGN,
	ROM_DATA_DC_IMPD_50_0C_0,
	ROM_DATA_DC_IMPD_20_0C_0,
	ROM_DATA_DC_IMPD_05_0C_0,
	ROM_DATA_DC_IMPD_70_25C_0,
	ROM_DATA_DC_IMPD_50_25C_0,
	ROM_DATA_DC_IMPD_20_25C_0,
	ROM_DATA_DC_IMPD_05_25C_0,
	ROM_DATA_DC_IMPD_70_0C_100,
	ROM_DATA_DC_IMPD_50_0C_100,
	ROM_DATA_DC_IMPD_20_0C_100,
	ROM_DATA_DC_IMPD_05_0C_100,
	ROM_DATA_DC_IMPD_70_25C_100,
	ROM_DATA_DC_IMPD_50_25C_100,
	ROM_DATA_DC_IMPD_20_25C_100,
	ROM_DATA_DC_IMPD_05_25C_100,
	ROM_DATA_DC_IMPD_70_0C_250,
	ROM_DATA_DC_IMPD_50_0C_250,
	ROM_DATA_DC_IMPD_20_0C_250,
	ROM_DATA_DC_IMPD_05_0C_250,
	ROM_DATA_DC_IMPD_70_25C_250,
	ROM_DATA_DC_IMPD_50_25C_250,
	ROM_DATA_DC_IMPD_20_25C_250,
	ROM_DATA_DC_IMPD_05_25C_250,
	ROM_DATA_DC_IMPD_70_0C_400,
	ROM_DATA_DC_IMPD_50_0C_400,
	ROM_DATA_DC_IMPD_20_0C_400,
	ROM_DATA_DC_IMPD_05_0C_400,
	ROM_DATA_DC_IMPD_70_25C_400,
	ROM_DATA_DC_IMPD_50_25C_400,
	ROM_DATA_DC_IMPD_20_25C_400,
	ROM_DATA_DC_IMPD_05_25C_400,
	ROM_DATA_PAGE_6_END = ROM_DATA_DC_IMPD_05_25C_400,
	/* End Page 6 */

	/* This element must always be last */
	ROM_DATA_SIZE
};

/* Data in Raw Eprom format and valid flag */
struct mmi_battery_cell {
	unsigned short        capacity;
	unsigned short        peak_voltage;
	unsigned short        dc_impedance;
	int                   batt_valid;
	unsigned short        cell_id;
};

struct mmi_battery_cell *mmi_battery_get_info(void);

#endif