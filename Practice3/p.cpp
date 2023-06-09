#include <iostream>
#include <fstream>
#include <queue>

double getRandom(double max_interval) {
	return max_interval * rand() / RAND_MAX;
}

int main() {
    std::ofstream output("logfile.txt", std::ios::out);
    output << "Simulation started" << std::endl;
    srand(time(NULL));
    double current_time = 0.0;
    double simulation_time = 3600.0;
    double request_coming = 23.0;
    double request_processing1 = 22;
    double request_processing2 = 14;
    std::queue<int> q1;
    std::queue<int> q2;
    bool is_device1_free = true;
    bool is_device2_free = true;
    double process1, process2;
    double new_request_time = getRandom(request_coming);
    int request_number = 1;
    while (current_time <= simulation_time) {
        if (new_request_time == 0.0) {
            new_request_time = getRandom(request_coming);
            int num = request_number++;
            output << "Time: " << current_time << " Application " << num << " has entered the system" << std::endl;
            if (q1.size() <= q2.size()) {
                q1.push(num);
                if (is_device1_free) {
                    is_device1_free = false;
                    process1 = getRandom(request_processing1);
                    output << "Time: " << current_time << " Application " << num << " is on the first device" << std::endl;
                } else {
                    output << "Time: " << current_time << " Application " << num << " is in the first queue" << std::endl;
                }
            } else {
                q2.push(num);
                if (is_device2_free) {
                    is_device2_free = false;
                    process2 = getRandom(request_processing2);
                    output << "Time: " << current_time << " Application " << num << " is on the second device" << std::endl;
                } else {
                    output << "Time: " << current_time << "Application " << num << " is in the second queue" << std::endl;
                }
            }
        } else {
            if (!is_device1_free && process1 == 0.0) {
                output << "Time: " << current_time << " Application " << q1.front() << " freed the first device and left the system" << std::endl;
                q1.pop();
                if (!q1.empty()) {
                    process1 = getRandom(request_processing1);
                    output << "Time: " << current_time << " Application " << q1.front() << " is on the first device" << std::endl;
                } else {
                    is_device1_free = true;
                }
            }
            if (!is_device2_free && process2 == 0.0) {
                output << "Time: " << current_time << " Application " << q2.front() << " freed the second device and left the system" << std::endl;
                q2.pop();
                if (!q2.empty()) {
                    process2 = getRandom(request_processing2);
                    output << "Time: " << current_time << " Application " << q2.front() << " is on the second device" << std::endl;
                } else {
                    is_device2_free = true;
                }
            }
        }
        double delta_time = new_request_time;
        if (!is_device1_free && delta_time > process1) {
            delta_time = process1;
        }
        if (!is_device2_free && delta_time > process2) {
            delta_time = process2;
        }
        new_request_time -= delta_time;
        if (!is_device1_free) {
            process1 -= delta_time;
        }
        if (!is_device2_free) {
            process2 -= delta_time;
        }
        current_time += delta_time;
    }
    output << "Simulation ended" << std::endl;
    output.close();
    return 0;
}