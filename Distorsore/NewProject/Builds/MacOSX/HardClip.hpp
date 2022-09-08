namespace brettstory {
	namespace audio {
		namespace clipping {
			class HardClip {
			public:
				static double ClipSample(double sample, double threshold);

			private:
				HardClip() {
				}
			};
		}
	}
}