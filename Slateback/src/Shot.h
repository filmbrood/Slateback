#pragma once

// Data class for details regarding shot objects, which are contained within the Roll class in a vector.
class Shot
{
public:
	Shot() {}
	~Shot() {}

public:
	// Methods for setting member variables. Names are self-explanatory.
	void SetScene(std::string scene);
	void SetTake(unsigned int take);
	void SetFPS(std::string fps);
	void SetLens(std::string lens);
	void SetFStop(std::string fstop);
	void SetISO(std::string iso);
	void SetColorTemp(std::string colortemp);
	void SetFilter(std::string filter);

	// Methods for returning member variables.
	std::string GetScene();
	unsigned int GetTake();
	std::string GetFPS();
	std::string GetLens();
	std::string GetFStop();
	std::string GetISO();
	std::string GetColorTemp();
	std::string GetFilter();

	template<class Archive>
	void serialize(Archive& archive); // Serializes class using Cereal library

private:
	std::string m_Scene;
	unsigned int m_Take;
	std::string m_FPS;
	std::string m_Lens;
	std::string m_FStop;
	std::string m_ISO;
	std::string m_ColorTemp;
	std::string m_Filter;
};

template<class Archive>
inline void Shot::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_Scene), CEREAL_NVP(m_Take), CEREAL_NVP(m_FPS), CEREAL_NVP(m_Lens), CEREAL_NVP(m_FStop), CEREAL_NVP(m_ISO), CEREAL_NVP(m_ColorTemp), CEREAL_NVP(m_Filter));
}
