//---------------------------------------------------------------------------

#ifndef quiz_game_projectH
#define quiz_game_projectH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *questionLabel;
	TRadioButton *answer1Button;
	TRadioButton *answer2Button;
	TRadioButton *answer3Button;
	TButton *submitButton;
	TRadioButton *answer4Button;
	TLabel *Label2;
	TLabel *goodGuesses;
	TLabel *Label4;
	TLabel *badGuesses;
	TLabel *guessPercentage;
	TLabel *percentage;
	TLabel *percentageLabel;
	TLabel *endText;
	void __fastcall answer1ButtonChange(TObject *Sender);
	void __fastcall answer2ButtonChange(TObject *Sender);
	void __fastcall answer3ButtonChange(TObject *Sender);
	void __fastcall answer4ButtonChange(TObject *Sender);
	void __fastcall submitButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
