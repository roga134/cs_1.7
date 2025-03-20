class CT
{
	private:
		bool HaveKitDef;
		bool IsBoombDef;
	public:
		CT();
		CT(CT& SCT);
		CT(bool SHaveKitDef , bool SIsBoombDef);
		~CT();

		void SetHaveKitDef(bool SHaveKitDef);
		void SetIsBoombDef(bool SIsBoombDef);

		bool GetHaveKitDef();
		bool GetIsBoombDef();

		bool operator==(CT& SCT);
		bool operator!=(CT& SCT);
		void operator=(CT& SCT);
};