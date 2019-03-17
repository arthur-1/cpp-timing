#ifndef _TIMING_H
#define _TIMING_H
#include <stdlib.h>
#include <sys/time.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>

/**
 * This class is based on the Ligra Benchmark suite's timing utilities:
 * https://github.com/jshun/ligra
 */

class Timing {
private:
	bool active;	
	double start_time;
	double stop_time;
	double elapsed_time;
	double total_time;
	int trial_count;
	std::vector<double> trials;
	
	// This method is directly taken from the Ligra Benchmark suite timing utility file (there, the method is called getTime())
	double get_time() {
		timeval now;
		struct timezone tzp = {0, 0};
		gettimeofday(&now, &tzp);
		return ((double) now.tv_sec) + ((double) now.tv_usec)/1000000.;
	}

public:	
	Timing() {
		this->active = false;	
		this->start_time = 0;
		this->stop_time = 0;
		this->elapsed_time = 0;
		this->total_time = 0;
		this->trial_count = 0;
	}

	void start() {
		this->active = true;
		this->elapsed_time = 0;
		this->stop_time = 0;
		this->start_time = get_time(); 
	}

	void stop() {
		this->stop_time = get_time();
		this->active = false;
	    this->elapsed_time = this->stop_time - this->start_time;
		this->total_time += this->elapsed_time;
		this->trial_count++;
		this->trials.push_back(this->elapsed_time);
	}

	double get_total_time() {
		return this->total_time;
	}

	double get_elapsed_time() {
		return this->elapsed_time;
	}

	double get_average_time() {
		return this->total_time / this->trial_count;
	}

	double get_percent_sample_standard_deviation() {
		double squared_total = 0;	
		for (int i = 0; i < this->trial_count; i++) {
			squared_total += (this->trials[i] - this->get_average_time());
		}

		if (this->trial_count > 1) return ((std::sqrt((1 / (this->trial_count - 1)) * squared_total)) / this->get_average_time()) * 100;
		// If only one trial was run, give 0 standard deviation	
		return 0;	
	}

	int get_num_timed_trials() {
		return this->trial_count;
	}

};
#endif

