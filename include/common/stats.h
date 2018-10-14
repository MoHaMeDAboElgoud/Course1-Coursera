#ifndef __STATS_H__
#define __STATS_H__



void print_array(unsigned char *inputArray, unsigned int size);
void PRINTF_Stats(unsigned char *inputArray,unsigned int size);

/**
 * @brief Returns the mean value of array
 *
 * This function finds the mean of the array
 * @param *inputArray unsigned pointer to input array
 * @param size integer type, the length of the array
 *
 * @return The mean value of the array
 */
float find_mean(unsigned char *inputArray, unsigned int size);

/**
 * @brief Returns the median value of array
 *
 * This function finds the mean of the array
 * @param *inputArray unsigned pointer to input array
 * @param size integer type, the length of the array
 *
 * @return The mean value of the array
 */
int find_median(unsigned char *inputArray, unsigned int size);

/**
 * @brief Returns the min value of array
 *
 * This function finds the mean of the array
 * @param *inputArray unsigned pointer to input array
 * @param size integer type, the length of the array
 *
 * @return The min value of the array
 */
int find_min(unsigned char *inputArray, unsigned int size);

/**
 * @brief Returns the max value of array
 *
 * This function finds the mean of the array
 * @param *inputArray unsigned pointer to input array
 * @param size integer type, the length of the array
 *
 * @return The max value of the array
 */
int find_max(unsigned char *inputArray, unsigned int size);

/**
 * @brief Returns a sorted array
 *
 * This function sort the array in an increasing order
 * @param *inputArray unsigned pointer to input array
 * @param size integer type, the length of the array
 *
 * @return The sorted value of the array
 */
void insertionSort(unsigned char *inputArray, unsigned int size);

/**
 * @brief Prints an array to the screen
 *
 * This function print each of the elements in the array
 * @param *inputArray unsigned pointer to input array
 * @param size integer type, the length of the array
 *
 * @return Prints an array to the screen
 */
void printArray(unsigned char *inputArray,unsigned int size);

/**
 * @brief Prints the statistics of an array
 *
 * This function prints the stats of the array by calling the other functions
 *
 * @return Prints the statistics of an array (mean, median, max, min)
 */
void printStats(unsigned char *inputArray,unsigned int size);

#endif /* __STATS_H__ */
