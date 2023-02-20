import UIKit

class ViewController: UIViewController {

	// create variables to hold user input
	var nickname = ""
	var moneyUnit = ""
	var hourlyWage: Double = 0.0

	// create timer and counter variables
	var timer = Timer()
	var seconds = 0.0

	// create labels to display time worked and earnings
	let timeLabel = UILabel()
	let earningsLabel = UILabel()

	// create input fields and buttons
	let nicknameField = UITextField()
	let moneyUnitField = UITextField()
	let hourlyWageField = UITextField()
	let startButton = UIButton()
	let stopButton = UIButton()

	override func viewDidLoad() {
		super.viewDidLoad()

		// set up input fields and buttons
		nicknameField.frame = CGRect(x: 20, y: 100, width: 200, height: 50)
		nicknameField.borderStyle = .roundedRect
		nicknameField.placeholder = "Nickname"
		view.addSubview(nicknameField)

		moneyUnitField.frame = CGRect(x: 20, y: 160, width: 200, height: 50)
		moneyUnitField.borderStyle = .roundedRect
		moneyUnitField.placeholder = "Money Unit"
		view.addSubview(moneyUnitField)

		hourlyWageField.frame = CGRect(x: 20, y: 220, width: 200, height: 50)
		hourlyWageField.borderStyle = .roundedRect
		hourlyWageField.placeholder = "Hourly Wage"
		hourlyWageField.keyboardType = .decimalPad
		view.addSubview(hourlyWageField)

		startButton.frame = CGRect(x: view.frame.width/2 - 75, y: 300, width: 150, height: 50)
		startButton.setTitle("Start", for: .normal)
		startButton.setTitleColor(.blue, for: .normal)
		startButton.addTarget(self, action: #selector(startTimer), for: .touchUpInside)
		view.addSubview(startButton)

		stopButton.frame = CGRect(x: view.frame.width/2 - 75, y: 360, width: 150, height: 50)
		stopButton.setTitle("Stop", for: .normal)
		stopButton.setTitleColor(.red, for: .normal)
		stopButton.addTarget(self, action: #selector(stopTimer), for: .touchUpInside)
		stopButton.isEnabled = false
		view.addSubview(stopButton)

		// set up time label
		timeLabel.frame = CGRect(x: 0, y: 50, width: view.frame.width, height: 50)
		timeLabel.textAlignment = .center
		view.addSubview(timeLabel)

		// set up earnings label
		earningsLabel.frame = CGRect(x: 0, y: 420, width: view.frame.width, height: 50)
		earningsLabel.textAlignment = .center
		view.addSubview(earningsLabel)
	}

	@objc func startTimer() {
		// get user input from input fields
		nickname = nicknameField.text ?? ""
		moneyUnit = moneyUnitField.text ?? ""
		hourlyWage = Double(hourlyWageField.text ?? "") ?? 0.0

		// disable input fields and start button
		nicknameField.isEnabled = false
		moneyUnitField.isEnabled = false
		hourlyWageField.isEnabled = false
		startButton.isEnabled = false

		// enable stop button and start timer
		stopButton.isEnabled = true
		timer = Timer.scheduledTimer(time
