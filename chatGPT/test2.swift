import UIKit

class ViewController: UIViewController {

	// set initial values for user information
	var nickname = ""
	var moneyUnit = "$"
	var hourlyWage = 20.0

	// create timer and counter variables
	var timer = Timer()
	var seconds = 0.0

	// create labels to display user information, time worked, and earnings
	let userInfoLabel = UILabel()
	let timeLabel = UILabel()
	let earningsLabel = UILabel()

	// create start and stop buttons
	let startButton = UIButton()
	let stopButton = UIButton()

	override func viewDidLoad() {
		super.viewDidLoad()

		// set up user information label
		userInfoLabel.frame = CGRect(x: 0, y: 50, width: view.frame.width, height: 50)
		userInfoLabel.textAlignment = .center
		view.addSubview(userInfoLabel)

		// set up time label
		timeLabel.frame = CGRect(x: 0, y: 100, width: view.frame.width, height: 50)
		timeLabel.textAlignment = .center
		view.addSubview(timeLabel)

		// set up earnings label
		earningsLabel.frame = CGRect(x: 0, y: 150, width: view.frame.width, height: 50)
		earningsLabel.textAlignment = .center
		view.addSubview(earningsLabel)

		// create start button
		startButton.frame = CGRect(x: 50, y: 250, width: 100, height: 50)
		startButton.backgroundColor = .green
		startButton.setTitle("Start", for: .normal)
		startButton.addTarget(self, action: #selector(startTimer), for: .touchUpInside)
		view.addSubview(startButton)

		// create stop button
		stopButton.frame = CGRect(x: view.frame.width - 150, y: 250, width: 100, height: 50)
		stopButton.backgroundColor = .red
		stopButton.setTitle("Stop", for: .normal)
		stopButton.addTarget(self, action: #selector(stopTimer), for: .touchUpInside)
		stopButton.isEnabled = false
		view.addSubview(stopButton)

		// display user information label with initial values
		displayUserInfo()
	}

	// function to display user information in label
	func displayUserInfo() {
		userInfoLabel.text = "Nickname: \(nickname)\nMoney Unit: \(moneyUnit)\nHourly Wage: \(moneyUnit)\(hourlyWage)"
	}

	// function to start the timer
	@objc func startTimer() {
		// enable stop button and disable start button
		stopButton.isEnabled = true
		startButton.isEnabled = false

		// create timer that updates every second
		timer = Timer.scheduledTimer(timeInterval: 1.0, target: self, selector: #selector(updateTimer), userInfo: nil, repeats: true)
	}

	// function to stop the timer
	@objc func stopTimer() {
		// disable stop button and enable start button
		stopButton.isEnabled = false
		startButton.isEnabled = true

		// stop the timer
		timer.invalidate()

		// calculate earnings and update earnings label
		let earnings = hourlyWage * (seconds / 3600.0)
		earningsLabel.text = String(format: "Earnings: \(moneyUnit)%.2f", earnings)
	}

	@objc func updateTimer() {
		// increment seconds counter
		seconds += 1.0

		// update
