# cpp-timing
A class containing useful timing utilities for C++

To use this file, include it, and instantiate a timing object with `Timing timer = Timing()`. To time a trial, use `timer.start()` before the code you wish to time. After the timed code region, use `timer.stop()` to stop the timer. You can use the `timer.start()` and `timer.stop()` combination multiple times in succession, and the class automatically adds each trial. When you wish to recieve the measured data, you can use `timer.get_average_time()` to get the average trial time, `timer.get_percent_sample_standard_deviation()` to get the sample statistic standard deviation (as a percent of the average trial time). Read the class to see other available methods.
