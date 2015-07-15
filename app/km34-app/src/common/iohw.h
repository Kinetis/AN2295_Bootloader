/******************************************************************************
 * (c) Copyright 2013, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      iohw.h
 * @version   1.0.2.0
 * @date      Nov-21-2014
 * @brief     Basic I/O hardware addressing using Bit Manipulation Engine (BME).
 ******************************************************************************/
#ifndef __IOHW_H
#define __IOHW_H

/******************************************************************************
 * Hardware accelerated basic I/O operations
 ******************************************************************************/
#define IO_AND(sz,reg,val)                                                    \
  *((uint##sz volatile*)((uint32)&reg|0x04000000))=(uint##sz)(val)
#define IO_OR(sz,reg,val)                                                     \
  *((uint##sz volatile*)((uint32)&reg|0x08000000))=(uint##sz)(val)
#define IO_XOR(sz,reg,val)                                                    \
  *((uint##sz volatile*)((uint32)&reg|0x0C000000))=(uint##sz)(val)
#define IO_BFI(sz,reg,shift,width,val)                                        \
  *((uint##sz volatile*)((uint32)&reg|0x10000000|(shift<<23)|                 \
    ((width-1)<<19)))=((uint##sz)(val)<<shift)
#define IO_LAC1(sz,reg,shift)                                                 \
  (uint8)(*((uint##sz volatile*)((uint32)&reg|0x08000000|(shift<<21))))
#define IO_LAS1(sz,reg,shift)                                                 \
  (uint8)(*((uint##sz volatile*)((uint32)&reg|0x0C000000|(shift<<21))))
#define IO_BFX(sz,reg,shift,width)                                            \
  *((uint##sz volatile*)((uint32)&reg|0x10000000|(shift<<23)|((width-1)<<19)))

/******************************************************************************
* Basic I/O hardware addressing macros.
*
*//*! @addtogroup io_macros
* @{
*******************************************************************************/
/***************************************************************************//*!
 * @brief   Performs a bit-wise AND operation on byte (8-bit) peripheral
 *          register.
 * @details The <c>ioandb</c> macro performs a bit-wise AND of the argument
 *          <c>val</c> and a byte (8-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   val     @ref uint8 AND mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioandb(reg,val) IO_AND(8,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise AND operation on halfword (16-bit) peripheral
 *          register.
 * @details The <c>ioandh</c> macro performs a bit-wise AND of the argument
 *          <c>val</c> and a halfword (8-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   val     @ref uint16 AND mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioandh(reg,val) IO_AND(16,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise AND operation on word (32-bit) peripheral
 *          register.
 * @details The <c>ioandw</c> macro performs a bit-wise AND of the argument
 *          <c>val</c> and a word (32-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   val     @ref uint32 AND mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioandw(reg,val) IO_AND(32,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise OR operation on byte (8-bit) peripheral
 *          register.
 * @details The <c>ioorb</c> macro performs a bit-wise OR of the argument
 *          <c>val</c> OR a byte (8-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   val     @ref uint8 OR mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioorb(reg,val)  IO_OR(8,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise OR operation on halfword (16-bit) peripheral
 *          register.
 * @details The <c>ioorh</c> macro performs a bit-wise OR of the argument
 *          <c>val</c> and a halfword (8-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   val     @ref uint16 OR mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioorh(reg,val)  IO_OR(16,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise OR operation on word (32-bit) peripheral
 *          register.
 * @details The <c>ioorw</c> macro performs a bit-wise OR of the argument
 *          <c>val</c> and a word (32-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   val     @ref uint32 OR mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioorw(reg,val)  IO_OR(32,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise XOR operation on byte (8-bit) peripheral
 *          register.
 * @details The <c>ioxorb</c> macro performs a bit-wise XOR of the argument
 *          <c>val</c> XOR a byte (8-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   val     @ref uint8 XOR mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioxorb(reg,val) IO_XOR(8,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise XOR operation on halfword (16-bit) peripheral
 *          register.
 * @details The <c>ioxorh</c> macro performs a bit-wise XOR of the argument
 *          <c>val</c> and a halfword (8-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   val     @ref uint16 XOR mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioxorh(reg,val) IO_XOR(16,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit-wise XOR operation on word (32-bit) peripheral
 *          register.
 * @details The <c>ioxorw</c> macro performs a bit-wise XOR of the argument
 *          <c>val</c> and a word (32-bit) register defined by the argument
 *          <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   val     @ref uint32 XOR mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioxorw(reg,val) IO_XOR(32,reg,val)

/***************************************************************************//*!
 * @brief   Clear bits in a byte (8-bit) peripheral register.
 * @details The <c>ioclrb</c> macro clears bits, defined by argument <c>val</c>,
 *          in a byte (8-bit) peripheral register defined by argument <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   val     @ref uint8 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioclrb(reg,val) IO_AND(8,reg,~(val))

/***************************************************************************//*!
 * @brief   Clear bits in a halfword (16-bit) peripheral register.
 * @details The <c>ioclrh</c> macro clears bits, defined by argument <c>val</c>,
 *          in a halfword (16-bit) peripheral register defined by argument
 *          <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   val     @ref uint16 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioclrh(reg,val) IO_AND(16,reg,~(val))

/***************************************************************************//*!
 * @brief   Clear bits in a word (32-bit) peripheral register.
 * @details The <c>ioclrw</c> macro clears bits, defined by argument <c>val</c>,
 *          in a word (32-bit) peripheral register defined by argument <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   val     @ref uint32 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioclrw(reg,val) IO_AND(32,reg,~(val))

/***************************************************************************//*!
 * @brief   Set bits in a byte (8-bit) peripheral register.
 * @details The <c>iosetb</c> macro sets bits, defined by argument <c>val</c>,
 *          in a byte (8-bit) peripheral register defined by argument <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   val     @ref uint8 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iosetb(reg,val) IO_OR(8,reg,val)

/***************************************************************************//*!
 * @brief   Set bits in a halfword (16-bit) peripheral register.
 * @details The <c>ioseth</c> macro sets bits, defined by argument <c>val</c>,
 *          in a halfword (16-bit) peripheral register defined by argument
 *          <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   val     @ref uint16 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define ioseth(reg,val) IO_OR(16,reg,val)

/***************************************************************************//*!
 * @brief   Set bits in a word (32-bit) peripheral register.
 * @details The <c>iosetw</c> macro sets bits, defined by argument <c>val</c>,
 *          in a word (32-bit) peripheral register defined by argument <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   val     @ref uint32 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iosetw(reg,val) IO_OR(32,reg,val)

/***************************************************************************//*!
 * @brief   Toggle bits in a byte (8-bit) peripheral register.
 * @details The <c>iotglb</c> macro toggles bits, defined by argument <c>val</c>,
 *          in a byte (8-bit) peripheral register defined by argument <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   val     @ref uint8 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iotglb(reg,val) IO_XOR(8,reg,val)

/***************************************************************************//*!
 * @brief   Toggle bits in a halfword (16-bit) peripheral register.
 * @details The <c>iotglh</c> macro toggles bits, defined by argument <c>val</c>,
 *          in a halfword (16-bit) peripheral register defined by argument
 *          <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   val     @ref uint16 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iotglh(reg,val) IO_XOR(16,reg,val)

/***************************************************************************//*!
 * @brief   Toggle bits in a word (32-bit) peripheral register.
 * @details The <c>iotglw</c> macro toggles bits, defined by argument <c>val</c>,
 *          in a word (32-bit) peripheral register defined by argument <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   val     @ref uint32 bit mask.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iotglw(reg,val) IO_XOR(32,reg,val)

/***************************************************************************//*!
 * @brief   Performs a bit field insert BFI operation on byte (8-bit)
 *          peripheral register.
 * @details The <c>iobfib</c> macro inserts a bit field <c>val</c> of size
 *          <c>width</c> into a byte (8-bit) peripheral register defined by
 *          argument <c>reg</c>. The bit field is inserted into peripheral
 *          register <c>reg</c> starting at bit position defined by argument
 *          <c>shift</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   shift   Bit field position [0-7].
 * @param   width   Bit field size [1-8].
 * @param   val     @ref uint8 bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iobfib(reg,shift,width,val) IO_BFI(8,reg,shift,width,val)

/***************************************************************************//*!
 * @brief   Performs a bit field insert BFI operation on halfword (16-bit)
 *          peripheral register.
 * @details The <c>iobfih</c> macro inserts a bit field <c>val</c> of size
 *          <c>width</c> into a halfword (16-bit) peripheral register defined by
 *          argument <c>reg</c>. The bit field is inserted into peripheral
 *          register <c>reg</c> starting at bit position defined by argument
 *          <c>shift</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   shift   Bit field position [0-15].
 * @param   width   Bit field size [1-16].
 * @param   val     @ref uint16 bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iobfih(reg,shift,width,val) IO_BFI(16,reg,shift,width,val)

/***************************************************************************//*!
 * @brief   Performs a bit field insert BFI operation on word (32-bit)
 *          peripheral register.
 * @details The <c>iobfiw</c> macro inserts a bit field <c>val</c> of size
 *          <c>width</c> into a word (32-bit) peripheral register defined by
 *          argument <c>reg</c>. The bit field is inserted into peripheral
 *          register <c>reg</c> starting at bit position defined by argument
 *          <c>shift</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   shift   Bit field position [0-31].
 * @param   width   Bit field size [1-16].
 * @param   val     @ref uint16 bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iobfiw(reg,shift,width,val) IO_BFI(32,reg,shift,width,val)

/***************************************************************************//*!
 * @brief   Returns a 1-bit field of the byte (8-bit) peripheral register
 *          and clears the same bit.
 * @details The <c>iolac1b</c> macro returns a right justified and zero filled
 *          1-bit field from bit position defined by <c>shift</c> of a byte
 *          (8-bit) peripheral register defined by argument <c>reg</c>.
 *          The same bit is cleared.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   shift   Bit field position [0-7].
 * @return  @ref uint8 right justified and zero filled 1-bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iolac1b(reg,shift)          IO_LAC1(8,reg,shift)

/***************************************************************************//*!
 * @brief   Returns a 1-bit field of the halfword (16-bit) peripheral register
 *          and clears the same bit.
 * @details The <c>iolac1h</c> macro returns a right justified and zero filled
 *          1-bit field from bit position defined by <c>shift</c> of a halfword
 *          (16-bit) peripheral register defined by argument <c>reg</c>.
 *          The same bit is cleared.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   shift   Bit field position [0-15].
 * @return  @ref uint8 right justified and zero filled 1-bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iolac1h(reg,shift)          IO_LAC1(16,reg,shift)

/***************************************************************************//*!
 * @brief   Returns a 1-bit field of the word (32-bit) peripheral register
 *          and cleared the same bit.
 * @details The <c>iolac1w</c> macro returns a right justified and zero filled
 *          1-bit field from bit position defined by <c>shift</c> of a word
 *          (32-bit) peripheral register defined by argument <c>reg</c>.
 *          The same bit is cleared.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   shift   Bit field position [0-31].
 * @return  @ref uint8 right justified and zero filled 1-bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iolac1w(reg,shift)          IO_LAC1(32,reg,shift)

/***************************************************************************//*!
 * @brief   Returns a 1-bit field of the byte (8-bit) peripheral register
 *          and sets the same bit.
 * @details The <c>iolas1b</c> macro returns a right justified and zero filled
 *          1-bit field from bit position defined by <c>shift</c> of a byte
 *          (8-bit) peripheral register defined by argument <c>reg</c>.
 *          The same bit is set.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   shift   Bit field position [0-7].
 * @return  @ref uint8 right justified and zero filled 1-bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iolas1b(reg,shift)          IO_LAS1(8,reg,shift)

/***************************************************************************//*!
 * @brief   Returns a 1-bit field of the halfword (16-bit) peripheral register
 *          and sets the same bit.
 * @details The <c>iolas1h</c> macro returns a right justified and zero filled
 *          1-bit field from bit position defined by <c>shift</c> of a halfword
 *          (16-bit) peripheral register defined by argument <c>reg</c>.
 *          The same bit is set.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   shift   Bit field position [0-15].
 * @return  @ref uint8 right justified and zero filled 1-bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iolas1h(reg,shift)          IO_LAS1(16,reg,shift)

/***************************************************************************//*!
 * @brief   Returns a 1-bit field of the word (32-bit) peripheral register
 *          and sets the same bit.
 * @details The <c>iolas1w</c> macro returns a right justified and zero filled
 *          1-bit field from bit position defined by <c>shift</c> of a word
 *          (32-bit) peripheral register defined by argument <c>reg</c>.
 *          The same bit is set.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   shift   Bit field position [0-31].
 * @return  @ref uint8 right justified and zero filled 1-bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iolas1w(reg,shift)          IO_LAS1(32,reg,shift)

/***************************************************************************//*!
 * @brief   Returns a bit field of the byte (8-bit) peripheral register.
 * @details The <c>iobfxb</c> macro returns a bit field of size <c>width</c>,
 *          from bit position defined by <c>shift</c>, of a byte (8-bit)
 *          peripheral register defined by argument <c>reg</c>.
 * @param   reg     Byte (8-bit) peripheral register.
 * @param   shift   Bit field position [0-7].
 * @param   width   bit filed size [1-8].
 * @return  @ref uint8 right justified and zero filled bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iobfxb(reg,shift,width)     IO_BFX(8,reg,shift,width)

/***************************************************************************//*!
 * @brief   Returns a bit field of the halfword (16-bit) peripheral register.
 * @details The <c>iobfxh</c> macro returns a bit field of size <c>width</c>,
 *          from bit position defined by <c>shift</c>, of a halfword (16-bit)
 *          peripheral register defined by argument <c>reg</c>.
 * @param   reg     Halfword (16-bit) peripheral register.
 * @param   shift   Bit field position [0-15].
 * @param   width   bit filed size [1-16].
 * @return  @ref uint16 right justified and zero filled bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iobfxh(reg,shift,width)     IO_BFX(16,reg,shift,width)

/***************************************************************************//*!
 * @brief   Returns a bit field of the word (32-bit) peripheral register.
 * @details The <c>iobfxw</c> macro returns a bit field of size <c>width</c>,
 *          from bit position defined by <c>shift</c>, of a word (32-bit)
 *          peripheral register defined by argument <c>reg</c>.
 * @param   reg     Word (32-bit) peripheral register.
 * @param   shift   Bit field position [0-31].
 * @param   width   bit filed size [1-32].
 * @return  @ref uint32 right justified and zero filled bit field value.
 * @note    Implemented as an inline macro.
 ******************************************************************************/
#define iobfxw(reg,shift,width)     IO_BFX(32,reg,shift,width)
/*! @} End of io_macros                                                       */

#endif /* __IOHW_H */
