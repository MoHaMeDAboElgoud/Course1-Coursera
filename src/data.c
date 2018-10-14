#include "data.h"
#include "memory.h"
#include "platform.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t digits = 0;
  uint8_t last_digit;
  bool negative_decimal = false;

  if(ptr == NULL){
	#ifdef VERBOSE
	    PRINTF("input ptr is a NULL pointer.\r\n");
	#endif
  }
  else 
	if(base != BASE_2 && base != BASE_8 && base != BASE_10 && base != BASE_16){
		#ifdef VERBOSE
		    PRINTF("unsupported base input.\r\n");
		#endif
  }
  else{
    if(data == 0){
      *ptr = 0;
      ptr++;
      digits++;
    }
    else{
      if (base == BASE_10 && data < 0){
        negative_decimal = true;
        data = -data;
      }

      while(data != 0){
        last_digit = data % base;
        *ptr = (last_digit >= 10) ? last_digit - 10 + 'A' : last_digit + '0';
        data /= base;
        ptr++;
        digits++;
      }

      if(negative_decimal){
        *ptr = '-';
        ptr++;
        digits++;
      }
      my_reverse(ptr - digits, digits);
      *ptr = '\0';
      digits++;
    }
  }
  return  digits;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  const uint8_t MAX_DATASET_SIZE = 33;
  int32_t number = 0;
  uint8_t digit;
  uint8_t * aux;
  bool negative = false;

  if(ptr == NULL){
#ifdef VERBOSE
    PRINTF("Error: Argument is a NULL pointer.\r\n");
#endif
  }
  else if(digits == 0 || digits > MAX_DATASET_SIZE){
#ifdef VERBOSE
    PRINTF("Error: Dataset is empty or too long.\r\n");
#endif
  }
  else if(*(ptr + digits - 1) != '\0'){
#ifdef VERBOSE
    PRINTF("Error: Wrong dataset terminator.\r\n");
#endif
  }
  else if(base != BASE_2 && base != BASE_8 && base != BASE_10 &&
          base != BASE_16){
#ifdef VERBOSE
    PRINTF("Error: Wrong base argument.\r\n");
#endif
  }
  else{
    aux = ptr;
    bool valid = true;

    while(aux < ptr + digits){
      if(!(*aux >= '0' && *aux <= '9') &&
         !(*aux >= 'a' && *aux <= 'f') &&
         !(*aux >= 'A' && *aux <= 'F') &&
         !(*aux == '-') && !(*aux == '\0')){
#ifdef VERBOSE
    PRINTF("Error: Dataset contains invalid character.\r\n");
#endif
        valid = false;
        break;
      }
      aux++;
    }

    if(valid){
      if(base == BASE_10 && *ptr == '-' && digits >= 2){
        negative = true;
        ptr++;
      }

      while(*ptr != '\0'){
        if(*ptr >= 'A' && *ptr <= 'F'){
          digit = *ptr - 'A' + 10;
        }
        else if(*ptr >= 'a' && *ptr <= 'f'){
          digit = *ptr - 'a' + 10;
        }
        else{
          digit = *ptr - '0';
        }
        number = number * base + digit;
        ptr++;
      }

      if (negative) number *= -1;
    }
  }
  return number;
}