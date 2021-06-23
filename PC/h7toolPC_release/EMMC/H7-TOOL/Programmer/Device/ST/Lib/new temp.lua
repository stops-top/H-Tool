FLASH_BASE 		= 0x40022000 
FLASH_ACR 		= 0x40022000
FLASH_PDKEYR 	= 0x40022004
FLASH_KEYR 		= 0x40022008
FLASH_OPTKEYR 	= 0x4002200C
FLASH_SR 		= 0x40022010
FLASH_CR 		= 0x40022014
FLASH_ECCR 		= 0x40022018

FLASH_OPTR 		= 0x40022020
FLASH_PCROP1SR 	= 0x40022024
FLASH_PCROP1ER 	= 0x40022028
FLASH_WRP1AR 	= 0x4002202C
FLASH_WRP1BR 	= 0x40022030

FLASH_PCROP2SR 	= 0x40022044
FLASH_PCROP2ER 	= 0x40022048
FLASH_WRP2AR 	= 0x4002204C
FLASH_WRP2BR 	= 0x40022050

FLASH_SEC1R 	= 0x40022070
FLASH_SEC2R 	= 0x40022074
--
FLASH_KEY1		= 0x45670123
FLASH_KEY2 		= 0xCDEF89AB
FLASH_OPTKEY1	= 0x08192A3B
FLASH_OPTKEY2	= 0x4C5D6E7F

--Flash Control Register definitions
-- FLASH_CR_PG             ((u32)(  1U      ))
-- FLASH_CR_PER            ((u32)(  1U <<  1))
-- FLASH_CR_MER1           ((u32)(  1U <<  2))
-- FLASH_CR_PNB_MSK        ((u32)(0x7F <<  3))
-- FLASH_CR_BKER           ((u32)(  1U << 11))
-- FLASH_CR_MER2           ((u32)(  1U << 15))
-- FLASH_CR_STRT           ((u32)(  1U << 16))
FLASH_CR_OPTSTRT = (1 << 17)
-- FLASH_CR_FSTPG          ((u32)(  1U << 18))
FLASH_OBL_LAUNCH = (1 << 27)  --   ((u32)(  1U << 27))
-- FLASH_CR_OPTLOCK        ((u32)(  1U << 30))
-- FLASH_CR_LOCK           ((u32)(  1U << 31))

--Flash Status Register definitions
-- #define FLASH_SR_EOP            ((u32)(  1U      ))
-- #define FLASH_SR_OPERR          ((u32)(  1U <<  1))
-- #define FLASH_SR_PROGERR        ((u32)(  1U <<  3))
-- #define FLASH_SR_WRPERR         ((u32)(  1U <<  4))
-- #define FLASH_SR_PGAERR         ((u32)(  1U <<  5))
-- #define FLASH_SR_SIZERR         ((u32)(  1U <<  6))
-- #define FLASH_SR_PGSERR         ((u32)(  1U <<  7))
-- #define FLASH_SR_MISSERR        ((u32)(  1U <<  8))
-- #define FLASH_SR_FASTERR        ((u32)(  1U <<  9))
-- #define FLASH_SR_RDERR          ((u32)(  1U << 14))
-- #define FLASH_SR_OPTVERR        ((u32)(  1U << 16))
FLASH_SR_BSY  = (1 << 16)	--   ((u32)(  1U << 16))

--芯片专有的整片擦除
function MCU_EraseMass(void)
	local i
	
	print("+++MCU_EraseMass()")
	
	--先加密，再解密
	print("+++set protect")
	pg_write32(FLASH_KEYR, FLASH_KEY1)
	pg_write32(FLASH_KEYR, FLASH_KEY2)

	pg_write32(FLASH_OPTKEYR, FLASH_OPTKEY1)
	pg_write32(FLASH_OPTKEYR, FLASH_OPTKEY2)

	pg_write32(FLASH_OPTR, 0xFFFEF8AA)

	pg_write32(FLASH_CR, pg_read32(FLASH_CR) | FLASH_CR_OPTSTRT)
	pg_write32(FLASH_CR, pg_read32(FLASH_CR) | FLASH_OBL_LAUNCH)
	
 	for i = 1, 1000, 1 do
 		if ((pg_read32(FLASH_CR) & FLASH_OBL_LAUNCH) == 0) then
 			break
 		end
 		delayms(1)
	end
	
 	for i = 1, 1000, 1 do
 		if ((pg_read32(FLASH_SR) & FLASH_SR_BSY) == 0) then
 			break
 		end
 		delayms(1)
	end
	
	--解密
	print("+++reset")
	pg_reset(20)
	
	print("remove protect")
	pg_write32(FLASH_KEYR, FLASH_KEY1)
	pg_write32(FLASH_KEYR, FLASH_KEY2)

	pg_write32(FLASH_OPTKEYR, FLASH_OPTKEY1)
	pg_write32(FLASH_OPTKEYR, FLASH_OPTKEY2)

	pg_write32(FLASH_OPTR, 0xFFFEF8AA)

	pg_write32(FLASH_CR, pg_read32(FLASH_CR) | FLASH_CR_OPTSTRT)
	pg_write32(FLASH_CR, pg_read32(FLASH_CR) | FLASH_OBL_LAUNCH)
	
 	for i = 1, 1000, 1 do
 		if ((pg_read32(FLASH_CR) & FLASH_OBL_LAUNCH) == 0) then
 			break
 		end
 		delayms(1)
	end
	
 	for i = 1, 1000, 1 do
 		if ((pg_read32(FLASH_SR) & FLASH_SR_BSY) == 0) then
 			break
 		end
 		delayms(1)
	end
	
	return "OK"
end

MCU_EraseMass()