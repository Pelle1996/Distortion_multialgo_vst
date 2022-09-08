#include "HardClip.hpp"
#include <cmath>

namespace brettstory {
	namespace audio {
		namespace clipping {
			double HardClip::ClipSample(double sample, double threshold) {
				return (0.5 * (abs(sample + threshold) - abs(sample - threshold))) / threshold;
			}
		}
	}
}