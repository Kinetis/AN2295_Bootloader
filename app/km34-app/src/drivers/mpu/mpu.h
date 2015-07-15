/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      mpu.h
 * @version   1.0.3.0
 * @date      Mar-02-2014
 * @brief     Memory Protection Unit (MPU) driver header file.
 ******************************************************************************/
#ifndef __MPU_H
#define __MPU_H

/******************************************************************************
 * Configuration structure definition                                         *
 ******************************************************************************/
typedef struct { uint32 W0, W1, W2, W3; } tMPU_RGD;

/***************************************************************************//*!
 *//*! @addtogroup mpu_spvr_attr
 * @{
 ******************************************************************************/
#define MPU_SPVR_RWX  (uint8)0  ///< R/W/X; read, write and execute allowed
#define MPU_SPVR_RX   (uint8)1  ///< R/X; read and execute allowed, but no write
#define MPU_SPVR_RW   (uint8)2  ///< R/W; read and write allowed, but no execute
#define MPU_SPVR_USER (uint8)3  ///< User mode rights defined for the same master
/*! @} End of mpu_spvr_attr                                                   */

/***************************************************************************//*!
 *//*! @addtogroup mpu_user_attr
 * @{
 ******************************************************************************/
#define MPU_USER_RWX  (uint8)7  ///< R/W/X; read, write and execute allowed (default)
#define MPU_USER_RW   (uint8)6  ///< R/W; read and write allowed, but no execute
#define MPU_USER_RX   (uint8)5  ///< R/X; read and execute allowed, but no write
#define MPU_USER_R    (uint8)4  ///< R; read allowed, but no write and execute
#define MPU_USER_WX   (uint8)3  ///< W/X; write and execute allowed, but no read
#define MPU_USER_W    (uint8)2  ///< W; write allowed, but no read and execute
#define MPU_USER_X    (uint8)1  ///< X; execute allowed, but no read and write
#define MPU_USER_NONE (uint8)0  ///< no user access allowed
/*! @} End of mpu_user_attr                                                   */

/******************************************************************************
* MPU default configurations used by MPU_RegInit() macro
*
*//*! @addtogroup mpu_region_config
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief Configures region descriptor, start and end addresses, process
 * identifier and mask to default (POR) state. Region descriptor is marked as
 * invalid (disabled).
 * @details Configures region descriptor, start and end addresses, process
 * identifier and mask to default (POR) state. Region descriptor is marked as
 * invalid (disabled).
 * @showinitializer
 ******************************************************************************/
#define MPU_RGD_DI_CONFIG                                                     \
(tMPU_RGD){                                                                   \
/* W0 */  SET(0x00000000),                                                    \
/* W1 */  SET(0x00000000),                                                    \
/* W2 */  CLR(MPU_WORD_M2PE_MASK)|SET(MPU_WORD_M2SM(0x03))|                   \
/* .. */  SET(MPU_WORD_M2UM(0x00))|                                           \
/* .. */  CLR(MPU_WORD_M0PE_MASK)|SET(MPU_WORD_M0SM(0x03))|                   \
/* .. */  SET(MPU_WORD_M0UM(0x00)),                                           \
/* W3 */  SET(MPU_WORD_PID(0x00))|SET(MPU_WORD_PIDMASK(0x00))|                \
/* .. */  CLR(MPU_WORD_VLD_MASK),                                             \
}

/***************************************************************************//*!
 * @brief Configures global region descriptor with start address=0x00000000, end
 * address=0xffffffff, M0SM and M2SM=0x03 (same as M0UM and M2UM), M0UM and
 * M2UM=0x07 (RWX access enabled) and process identifier and mask disabled.
 * @details Configures global region descriptor with start address=0x00000000, end
 * address=0xffffffff, M0SM and M2SM=0x03 (same as M0UM and M2UM), M0UM and
 * M2UM=0x07 (RWX access enabled) and process identifier and mask disabled.
 * @note Such global descriptor prevents region hit because granting permission
 * is a higher priority than denying access for overlapping regions.
 * @showinitializer
 ******************************************************************************/
#define MPU_RGD_EN_GLOBAL_CONFIG                                              \
(tMPU_RGD){                                                                   \
/* W0 */  SET(0x00000000),                                                    \
/* W1 */  SET(0xffffffff),                                                    \
/* W2 */  CLR(MPU_WORD_M2PE_MASK)|SET(MPU_WORD_M2SM(0x03))|                   \
/* .. */  SET(MPU_WORD_M2UM(0x07))|                                           \
/* .. */  CLR(MPU_WORD_M0PE_MASK)|SET(MPU_WORD_M0SM(0x03))|                   \
/* .. */  SET(MPU_WORD_M0UM(0x07)),                                           \
/* W3 */  SET(MPU_WORD_PID(0x00))|SET(MPU_WORD_PIDMASK(0x00))|                \
/* .. */  CLR(MPU_WORD_VLD_MASK),                                             \
}


/***************************************************************************//*!
 * @brief Basic configuration. Process identifier and mask are not included
 * in the region hit evaluation on any bus master. Region descriptor is marked
 * as valid (enabled).
 * @details Basic configuration. Process identifier and mask are not included
 * in the region hit evaluation on any bus master. Region descriptor is marked
 * as valid (enabled).
 * @param   cm0_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   cm0_user   Select one of the @ref mpu_user_attr.
 * @param   dma_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   dma_user   Select one of the @ref mpu_user_attr.
 * @param   start_addr 32-bit 0-mod-32 byte start address of the memory region.
 * @param   end_addr   32-bit 31-mod-32 byte end address of the memory region.
 * @showinitializer
 ******************************************************************************/
#define MPU_RGD_EN_CM0_PID_OFF_DMA_PID_OFF_CONFIG(cm0_spvr,cm0_user,dma_spvr, \
                                               dma_user,start_addr,end_addr)  \
(tMPU_RGD){                                                                   \
/* W0 */  SET((uint32)start_addr),                                            \
/* W1 */  SET((uint32)end_addr),                                              \
/* W2 */  CLR(MPU_WORD_M2PE_MASK)|SET(MPU_WORD_M2SM(dma_spvr))|               \
/* .. */  SET(MPU_WORD_M2UM(dma_user))|                                       \
/* .. */  CLR(MPU_WORD_M0PE_MASK)|SET(MPU_WORD_M0SM(cm0_spvr))|               \
/* .. */  SET(MPU_WORD_M0UM(cm0_user)),                                       \
/* W3 */  SET(MPU_WORD_PID(0x00))|SET(MPU_WORD_PIDMASK(0x00))|                \
/* .. */  SET(MPU_WORD_VLD_MASK),                                             \
}

/***************************************************************************//*!
 * @brief Advanced configuration. Process identifier and mask are included in
 * the region hit evaluation of the "CM0" master. Region descriptor is marked as
 * valid (enabled).
 * @details Advanced configuration. Process identifier and mask are included in
 * the region hit evaluation of the "CM0" master. Region descriptor is marked as
 * valid (enabled).
 * @param   cm0_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   cm0_user   Select one of the @ref mpu_user_attr.
 * @param   dma_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   dma_user   Select one of the @ref mpu_user_attr.
 * @param   pid        8-bit process identifier.
 * @param   pid_mask   8-bit process identifier mask.
 * @param   start_addr 32-bit 0-mod-32 byte start address of the memory region.
 * @param   end_addr   32-bit 31-mod-32 byte end address of the memory region.
 * @showinitializer
 ******************************************************************************/
#define MPU_RGD_EN_CM0_PID_ON_DMA_PID_OFF_CONFIG(cm0_spvr,cm0_user,dma_spvr,  \
                                              dma_user,pid,pid_mask,          \
                                              start_addr,end_addr)            \
(tMPU_RGD){                                                                   \
/* W0 */  SET((uint32)start_addr),                                            \
/* W1 */  SET((uint32)end_addr),                                              \
/* W2 */  CLR(MPU_WORD_M2PE_MASK)|SET(MPU_WORD_M2SM(dma_spvr))|               \
/* .. */  SET(MPU_WORD_M2UM(dma_user))|                                       \
/* .. */  SET(MPU_WORD_M0PE_MASK)|SET(MPU_WORD_M0SM(cm0_spvr))|               \
/* .. */  SET(MPU_WORD_M0UM(cm0_user)),                                       \
/* W3 */  SET(MPU_WORD_PID(pid))|SET(MPU_WORD_PIDMASK(pid_mask))|             \
/* .. */  SET(MPU_WORD_VLD_MASK),                                             \
}

/***************************************************************************//*!
 * @brief Advanced configuration. Process identifier and mask are included in
 * the region hit evaluation of the "DMA" master. Region descriptor is marked as
 * valid (enabled).
 * @details Advanced configuration. Process identifier and mask are included in
 * the region hit evaluation of the "DMA" master. Region descriptor is marked as
 * valid (enabled).
 * @param   cm0_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   cm0_user   Select one of the @ref mpu_user_attr.
 * @param   dma_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   dma_user   Select one of the @ref mpu_user_attr.
 * @param   pid        8-bit process identifier.
 * @param   pid_mask   8-bit process identifier mask.
 * @param   start_addr 32-bit 0-mod-32 byte start address of the memory region.
 * @param   end_addr   32-bit 31-mod-32 byte end address of the memory region.
 * @showinitializer
 ******************************************************************************/
#define MPU_RGD_EN_CM0_PID_OFF_DMA_PID_ON_CONFIG(cm0_spvr,cm0_user,dma_spvr,  \
                                              dma_user,pid,pid_mask,          \
                                              start_addr,end_addr)            \
(tMPU_RGD){                                                                   \
/* W0 */  SET((uint32)start_addr),                                            \
/* W1 */  SET((uint32)end_addr),                                              \
/* W2 */  SET(MPU_WORD_M2PE_MASK)|SET(MPU_WORD_M2SM(dma_spvr))|               \
/* .. */  SET(MPU_WORD_M2UM(dma_user))|                                       \
/* .. */  CLR(MPU_WORD_M0PE_MASK)|SET(MPU_WORD_M0SM(cm0_spvr))|               \
/* .. */  SET(MPU_WORD_M0UM(cm0_user)),                                       \
/* W3 */  SET(MPU_WORD_PID(pid))|SET(MPU_WORD_PIDMASK(pid_mask))|             \
/* .. */  SET(MPU_WORD_VLD_MASK),                                             \
}

/***************************************************************************//*!
 * @brief Advanced configuration. Process identifier and mask are included in the
 * region hit evaluation of the "CM0" and "DMA" masters. Region descriptor is
 * marked as valid (enabled).
 * @details Advanced configuration. Process identifier and mask are included in the
 * region hit evaluation of the "CM0" and "DMA" masters. Region descriptor is
 * marked as valid (enabled).
 * @param   cm0_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   cm0_user   Select one of the @ref mpu_user_attr.
 * @param   dma_spvr   Select one of the @ref mpu_spvr_attr.
 * @param   dma_user   Select one of the @ref mpu_user_attr.
 * @param   pid        8-bit process identifier.
 * @param   pid_mask   8-bit process identifier mask.
 * @param   start_addr 32-bit 0-mod-32 byte start address of the memory region.
 * @param   end_addr   32-bit 31-mod-32 byte end address of the memory region.
 * @showinitializer
 ******************************************************************************/
#define MPU_RGD_EN_CM0_PID_ON_DMA_PID_ON_CONFIG(cm0_spvr,cm0_user,dma_spvr,   \
                                             dma_user,pid,pid_mask,           \
                                             start_addr,end_addr)             \
(tMPU_RGD){                                                                   \
/* W0 */  SET((uint32)start_addr),                                            \
/* W1 */  SET((uint32)end_addr),                                              \
/* W2 */  SET(MPU_WORD_M2PE_MASK)|SET(MPU_WORD_M2SM(dma_spvr))|               \
/* .. */  SET(MPU_WORD_M2UM(dma_user))|                                       \
/* .. */  SET(MPU_WORD_M0PE_MASK)|SET(MPU_WORD_M0SM(cm0_spvr))|               \
/* .. */  SET(MPU_WORD_M0UM(cm0_user)),                                       \
/* W3 */  SET(MPU_WORD_PID(pid))|SET(MPU_WORD_PIDMASK(pid_mask))|             \
/* .. */  SET(MPU_WORD_VLD_MASK),                                             \
}
/*! @} End of mpu_region_config                                               */

/******************************************************************************
* MPU function and macro definitions
*
*//*! @addtogroup mpu_macro
* @{
*******************************************************************************/

#define _RGD1_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD1_WORD0=(uint32)tmp.W0; MPU_RGD1_WORD1=(uint32)tmp.W1;               \
  MPU_RGD1_WORD2=(uint32)tmp.W2; MPU_RGD1_WORD3=(uint32)tmp.W3;               \
}
#define _RGD2_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD2_WORD0=(uint32)tmp.W0; MPU_RGD2_WORD1=(uint32)tmp.W1;               \
  MPU_RGD2_WORD2=(uint32)tmp.W2; MPU_RGD2_WORD3=(uint32)tmp.W3;               \
}
#define _RGD3_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD3_WORD0=(uint32)tmp.W0; MPU_RGD3_WORD1=(uint32)tmp.W1;               \
  MPU_RGD3_WORD2=(uint32)tmp.W2; MPU_RGD3_WORD3=(uint32)tmp.W3;               \
}
#define _RGD4_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD4_WORD0=(uint32)tmp.W0; MPU_RGD4_WORD1=(uint32)tmp.W1;               \
  MPU_RGD4_WORD2=(uint32)tmp.W2; MPU_RGD4_WORD3=(uint32)tmp.W3;               \
}
#define _RGD5_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD5_WORD0=(uint32)tmp.W0; MPU_RGD5_WORD1=(uint32)tmp.W1;               \
  MPU_RGD5_WORD2=(uint32)tmp.W2; MPU_RGD5_WORD3=(uint32)tmp.W3;               \
}
#define _RGD6_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD6_WORD0=(uint32)tmp.W0; MPU_RGD6_WORD1=(uint32)tmp.W1;               \
  MPU_RGD6_WORD2=(uint32)tmp.W2; MPU_RGD6_WORD3=(uint32)tmp.W3;               \
}
#define _RGD7_INIT(tmp)                                                       \
{                                                                             \
  MPU_RGD7_WORD0=(uint32)tmp.W0; MPU_RGD7_WORD1=(uint32)tmp.W1;               \
  MPU_RGD7_WORD2=(uint32)tmp.W2; MPU_RGD7_WORD3=(uint32)tmp.W3;               \
}
/***************************************************************************//*!
* @brief   Initializes region descriptor.
* @details This macro initializes region descriptor by configurations for
*          supported bus masters; i.e. "CM0" and "DMA".
* @param   rgd         RGD1,RGD2,RGD3,RGD4,RGD5,RGD6,RGD7.
* @param   cfg         Select one of the @ref mpu_region_config.
* @note    Implemented as an inline macro.
* @warning The RGD0 descriptor has a special usage. It is intended for debug.
* Core cannot write to WORD0,1,3, registers otherwise hard fault occurs.
* In order to invalidate RGD0 for controlling access of "CM0" and "DMA" masters
* (not "DEBUG" master) call @ref MPU_DisableRGD0.
* @see     @ref MPU_RgdUpdate
******************************************************************************/
#define MPU_RgdInit(rgd,cfg) { register tMPU_RGD tmp=cfg; _##rgd##_INIT(tmp); }

#define _RGDCM0_ATTR_MASK (MPU_RGDAAC_M0PE_MASK|MPU_RGDAAC_M0SM_MASK|MPU_RGDAAC_M0UM_MASK)
#define _RGDDMA_ATTR_MASK (MPU_RGDAAC_M2PE_MASK|MPU_RGDAAC_M2SM_MASK|MPU_RGDAAC_M2UM_MASK)
#define _RGD0CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC0&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC0 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD0DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC0&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC0 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD1CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC1&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC1 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD1DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC1&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC1 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD2CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC2&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC2 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD2DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC2&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC2 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD3CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC3&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC3 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD3DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC3&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC3 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD4CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC4&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC4 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD4DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC4&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC4 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD5CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC5&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC5 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD5DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC5&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC5 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD6CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC6&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC6 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD6DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC6&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC6 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
#define _RGD7CM0_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC7&~_RGDCM0_ATTR_MASK                        \
  MPU_RGDAAC7 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M0PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M0SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M0UM_SHIFT));            \
}
#define _RGD7DMA_Update(spvr,user,pid_ctrl)                                   \
{                                                                             \
  register uint32 tmp = MPU_RGDAAC7&~_RGDDMA_ATTR_MASK                        \
  MPU_RGDAAC7 = tmp|(((uint32)pid_ctrl << MPU_RGDAAC_M2PE_SHIFT) |            \
                     ((uint32)spvr     << MPU_RGDAAC_M2SM_SHIFT) |            \
                     ((uint32)user     << MPU_RGDAAC_M2UM_SHIFT));            \
}
/***************************************************************************//*!
* @brief   Updates region descriptor.
* @details This macro updates region descriptor by configurations for supported
*          bus masters; i.e. "CM0" and "DMA".
* @param   rgd         RGD0,RGD1,RGD2,RGD3,RGD4,RGD5,RGD6,RGD7.
* @param   master      CM0,DMA.
* @param   spvr        Select one of the @ref mpu_spvr_attr.
* @param   user        Select one of the @ref mpu_user_attr.
* @param   pid_ctrl    TRUE  Process identifier and mask are included in the
*                            region hit evaluation\n
*                      FALSE Process identifier and mask are not included in
*                            the region hit evaluation.
* @note    Implemented as an inline macro.
* @see     @ref MPU_RgdInit
******************************************************************************/
#define MPU_RgdUpdate(rgd,master,spvr,user,pid_ctrl)                          \
                                _##rgd##master##_Update(spvr,user,pid_ctrl)

/***************************************************************************//*!
* @brief    Enables MPU on global level.
* @details  This macro enables MPU on global level by asserting MPU_CESR[VLD] bit.
* @note     Implemented as an inline macro.
* @see     @ref MPU_Disable
******************************************************************************/
#define MPU_Enable()          iosetw (MPU_CESR,MPU_CESR_VLD_MASK)

/***************************************************************************//*!
* @brief    Disables MPU on global level.
* @details  This macro disables MPU on global level by clearing MPU_CESR[VLD] bit.
* @note     Implemented as an inline macro.
* @see     @ref MPU_Enable
******************************************************************************/
#define MPU_Disable()         ioclrw (MPU_CESR,MPU_CESR_VLD_MASK)

/***************************************************************************//*!
* @brief    Disables overlapping RGD0 descriptor.
* @details  This macro disables RGD0 descriptor. The RGD0 descriptor will no
*           longer overlaps with other descriptors set for "CM0" and "DMA"
*           masters.
* @note     Implemented as an inline macro. The RGD0 descriptor is be still enabled
*           and overlapping with other regions to allow access "DEBUG" master.
******************************************************************************/
#define MPU_DisableRGD0()                                                     \
{                                                                             \
  MPU_RGDAAC0 = (((uint32)0l            << MPU_RGDAAC_M0PE_SHIFT) |           \
                 ((uint32)MPU_SPVR_USER << MPU_RGDAAC_M0SM_SHIFT) |           \
                 ((uint32)MPU_USER_NONE << MPU_RGDAAC_M0UM_SHIFT) |           \
                 ((uint32)0l            << MPU_RGDAAC_M2PE_SHIFT) |           \
                 ((uint32)MPU_SPVR_USER << MPU_RGDAAC_M2SM_SHIFT) |           \
                 ((uint32)MPU_USER_NONE << MPU_RGDAAC_M2UM_SHIFT));           \
}
/*! @} End of mpu_macro                                                       */

#endif /* __MPU_H */ 