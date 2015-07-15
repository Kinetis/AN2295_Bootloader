/******************************************************************************
 * (c) Copyright 2010-2015, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      mcm.h
 * @version   1.0.4.0
 * @date      Jun-11-2015
 * @brief     Miscellaneous Control Module (MCM) driver header file.
 ******************************************************************************/
#ifndef __MCM_H
#define __MCM_H

/***************************************************************************//*!
 *//*! @addtogroup mcm_master
 * @{
 ******************************************************************************/
#define MCM_CM0_MASTER (uint8)(1u << 0)   ///< CM0 Core Master (port number 0)
#define MCM_DMA_MASTER (uint8)(1u << 1)   ///< DMA Master (port number 2)
/*! @} End of mcm_master                                                      */

/***************************************************************************//*!
 *//*! @addtogroup mcm_master_attr
 * @{
 ******************************************************************************/
#define MCM_MASTER_FR_PRIV_SECURE                   0  ///< Master forced to {privileged, secure} (default)
#define MCM_MASTER_FR_USER_SECURE                   2  ///< Master forced to {user, secure}
#define MCM_MASTER_FR_USER_NONSEC                   3  ///< Master forced to {user, nonsecure}
#define MCM_MASTER_EN_PRIV_OR_USER_FR_SECURE        4  ///< Enable {privileged or user} and force {secure}
#define MCM_MASTER_EN_PRIV_OR_USER_FR_NONSEC        5  ///< Enable {privileged or user} and force {nonsecure}
#define MCM_MASTER_EN_PRIV_OR_USER_SECURE_OR_NONSEC 6  ///< Enable {privileged or user, secure or nonsecure}
/*! @} End of mcm_master_attr                                                 */

/******************************************************************************
* MCM function and macro definitions
*
*//*! @addtogroup mcm_macro
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Crossbar master access configuration and locking.
 * @details This macro configures access attributes for selected master(s) and
 * controls access into configuration attributes.
 * @param   mask   Select one or more OR'ed @ref mcm_master.
 * @param   attr   @ref mcm_master_attr.
 * @param   lock   TRUE  (configuration locked until next power on reset)\n
 *                 FALSE (configuration left opened for further changes).
 * @note    Implemented as an inline macro.
 * @warning Writing @ref MCM_CM0_MASTER access attributes must take special care.
 * Typically, the processor would use an @ref mcm_master_attr value of either
 * @ref MCM_MASTER_FR_PRIV_SECURE or @ref MCM_MASTER_EN_PRIV_OR_USER_SECURE_OR_NONSEC
 * because the other values can create a configuration where access to system
 * level resources is not allowed.
 * @see     @ref MCM_LoadPID
 ******************************************************************************/
#define MCM_SetMasterAttr(mask,attr,lock)                                     \
{                                                                             \
  register uint32 tmp=0l;                                                     \
  if ((mask) & MCM_CM0_MASTER)                                                \
    tmp|= (((uint32)attr<<MCM_MATCR_ATC0_SHIFT)|                              \
           ((uint32)lock<<MCM_MATCR_RO0_SHIFT));                              \
  if ((mask) & MCM_DMA_MASTER)                                                \
    tmp|= (((uint32)attr<<MCM_MATCR_ATC2_SHIFT)|                              \
          ((uint32)lock<<MCM_MATCR_RO2_SHIFT));                               \
  MCM_MATCR0=tmp;                                                             \
}

/***************************************************************************//*!
 * @brief   Loads process ID register.
 * @details This macro loads process ID register.
 * @param   pid     00h - Reserved for privileged secure tasks,
 *                  01h - 7Fh Allocated for user secure tasks,
 *                  80h - FFh Allocated for user nonsecure tasks.
 * @note    Implemented as an inline macro.
 * @see     @ref MCM_SetMasterAttr
 ******************************************************************************/
#define MCM_LoadPID(pid)    MCM_PID = (uint32)(pid)

/***************************************************************************//*!
 * @brief   Flash controller stalling control.
 * @details This macro controls stalling flash controller when flash is busy.
 *          Stalling flash controller must be set by this macro only just before
 *          the flash operation is executed and must be cleared when the
 *          operation completes.
 * @param   ctrl    FALSE Disables stalling flash controller when flash is busy
 *                  (default),
 *                  TRUE  Enables stalling flash controller when flash is busy.
 * @note    When software needs to access the flash memory while a flash memory
 *          resource is being manipulated by a flash command, software can
 *          enable a stall mechanism to avoid a read collision. The stall
 *          mechanism allows software to execute code from the same block on
 *          which flash operations are being performed. However, software must
 *          ensure the sector the flash operations are being performed on is not
 *          the same sector from which the code is executing. Implemented as an
 *          inline macro.
 ******************************************************************************/
#define MCM_SfcCtrl(ctrl)                                                     \
{                                                                             \
  if  (ctrl)        MCM_PLACR |= MCM_PLACR_ESFC_MASK;                         \
  else              MCM_PLACR &=~MCM_PLACR_ESFC_MASK;                         \
}

/***************************************************************************//*!
 * @brief   Flash controller speculation control.
 * @details This macro controls flash controller speculation.
 * @param   ctrl    FALSE Disables flash controller speculation,
 *                  TRUE  Enables flash controller speculation (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define MCM_FcsCtrl(ctrl)                                                     \
{                                                                             \
  if  (ctrl)        MCM_PLACR &=~MCM_PLACR_DFCS_MASK;                         \
  else              MCM_PLACR |= MCM_PLACR_DFCS_MASK;                         \
}

/***************************************************************************//*!
 * @brief   Flash data speculation control.
 * @details This macro controls flash data speculation.
 * @param   ctrl    FALSE Disables flash data speculation (default),
 *                  TRUE  Enables flash data speculation.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define MCM_FdsCtrl(ctrl)                                                     \
{                                                                             \
  if  (ctrl)        MCM_PLACR |= MCM_PLACR_EFDS_MASK;                         \
  else              MCM_PLACR &=~MCM_PLACR_EFDS_MASK;                         \
}

/***************************************************************************//*!
 * @brief   Flash controller cache control.
 * @details This macro controls flash controller cache.
 * @param   ctrl    FALSE Disables flash controller cache,
 *                  TRUE  Enables flash controller cache (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define MCM_FccCtrl(ctrl)                                                     \
{                                                                             \
  if  (ctrl)        MCM_PLACR &=~MCM_PLACR_DFCC_MASK;                         \
  else              MCM_PLACR |= MCM_PLACR_DFCC_MASK;                         \
}

/***************************************************************************//*!
 * @brief   Flash controller instruction caching control.
 * @details This macro controls flash controller instruction caching.
 * @param   ctrl    FALSE Disables flash controller instruction caching,
 *                  TRUE  Enables flash controller instruction caching (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define MCM_FcicCtrl(ctrl)                                                    \
{                                                                             \
  if  (ctrl)        MCM_PLACR &=~MCM_PLACR_DFCIC_MASK;                        \
  else              MCM_PLACR |= MCM_PLACR_DFCIC_MASK;                        \
}

/***************************************************************************//*!
 * @brief   Flash controller data caching control.
 * @details This macro controls flash controller data caching.
 * @param   ctrl    FALSE Disables flash controller data caching,
 *                  TRUE  Enables flash controller data caching (default).
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define MCM_FcdaCtrl(ctrl)                                                    \
{                                                                             \
  if  (ctrl)        MCM_PLACR &=~MCM_PLACR_DFCDA_MASK;                        \
  else              MCM_PLACR |= MCM_PLACR_DFCDA_MASK;                        \
}

/***************************************************************************//*!
 * @brief   Crossbar master arbitration control.
 * @details This macro controls arbitration for crossbar masters.
 * @param   ctrl    FALSE Sets fixed-priority arbitration (default),
 *                  TRUE  Sets round-robin arbitration.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define MCM_MasterArbCtrl(ctrl)                                               \
{                                                                             \
  if  (ctrl)        MCM_PLACR |= MCM_PLACR_ARB_MASK;                          \
  else              MCM_PLACR &=~MCM_PLACR_ARB_MASK;                          \
}

/***************************************************************************//*!
 * @brief   Initializes compute operation mode (CPO).
 * @details This macro initializes compute operation mode (CPO). Macro waits
 *          until compute operation acknowledge (CPOACK) bit is asserted
 *          notifying successful transition to CPO mode. Compute operation
 *          wakeup on interrupt or exception vector fetch is set optionally.
 * @param   wakeup  TRUE  Sets compute operation as well as wakeup by any
 *                        interrupt or exception vector fetch,
 *                  FALSE Sets compute operation (default).
 * @note    Implemented as an inline macro.
 * @see     @ref MCM_QuitCPO
 ******************************************************************************/
#define MCM_InitCPO(wakeup)                                                   \
{                                                                             \
  if (wakeup)       MCM_CPO = MCM_CPO_CPOREQ_MASK|MCM_CPO_CPOWOI_MASK;        \
  else              MCM_CPO = MCM_CPO_CPOREQ_MASK;                            \
  while (!(MCM_CPO & MCM_CPO_CPOACK_MASK));                                   \
}

/***************************************************************************//*!
 * @brief   Quits pending compute operation mode (CPO).
 * @details This macro quits pending compute operation mode (CPO). Macro waits
 *          until compute operation acknowledge (CPOACK) bit is de-asserted
 *          notifying successful transition to RUN or VLPR mode.
 * @note    Implemented as an inline macro.
 * @see     @ref MCM_InitCPO
 ******************************************************************************/
#define MCM_QuitCPO()                                                         \
{                                                                             \
  MCM_CPO = 0;                                                                \
  while (MCM_CPO & MCM_CPO_CPOACK_MASK);                                      \
}
/*! @} End of mcm_macro                                                       */

#endif /* __MCM_H */ 