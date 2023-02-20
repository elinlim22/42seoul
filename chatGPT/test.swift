import UIKit

class ViewController: UIViewController {

	// set hourly wage in dollars
	let hourlyWage = 20.0

	// create timer and counter variables
	var timer = Timer()
	var seconds = 0.0

	// create labels to display time worked and earnings
	let timeLabel = UILabel()
	let earningsLabel = UILabel()

	override func viewDidLoad() {
		super.viewDidLoad()

		// set up time label
		timeLabel.frame = CGRect(x: 0, y: 50, width: view.frame.width, height: 50)
		timeLabel.textAlignment = .center
		view.addSubview(timeLabel)

		// set up earnings label
		earningsLabel.frame = CGRect(x: 0, y: 100, width: view.frame.width, height: 50)
		earningsLabel.textAlignment = .center
		view.addSubview(earningsLabel)

		// create timer that updates every second
		timer = Timer.scheduledTimer(timeInterval: 1.0, target: self, selector: #selector(updateTimer), userInfo: nil, repeats: true)
	}

	@objc func updateTimer() {
		// increment seconds counter
		seconds += 1.0

		// update time label with formatted time string
		timeLabel.text = "Time Worked: \(timeString(time: seconds))"

		// calculate earnings and update earnings label
		let earnings = hourlyWage * (seconds / 3600.0)
		earningsLabel.text = String(format: "Earnings: $%.2f", earnings)
	}

	// convert time in seconds to formatted string
	func timeString(time: Double) -> String {
		let hours = Int(time) / 3600
		let minutes = Int(time) / 60 % 60
		let seconds = Int(time) % 60
		return String(format: "%02i:%02i:%02i", hours, minutes, seconds)
	}
}
