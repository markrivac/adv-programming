
public class Salary {

	public static void main(String[] args) {

		String oldSalary1 = "45632763";
		// new salary should be "4582854"

		String newSalary = getNewSalary(oldSalary1);
		System.out.println("old salary: " + oldSalary1);
		System.out.println("new salary: " + newSalary);

		double oldSalaryNumber = Double.parseDouble(oldSalary1);
		double newSalaryNumber = Double.parseDouble(newSalary);

		if (oldSalaryNumber <= newSalaryNumber) {
			System.out.println("The increment in the salary was about: " + (newSalaryNumber-oldSalaryNumber));
			System.out.println("success");
		}

	}

	public static String getNewSalary(String oldSalary) {

		char[] salary = salaryToArray(oldSalary);
		makeFirstChange(salary);
		changeRightSide(salary);

		String newSalary = "";

		for (char c : salary) {
			newSalary += c;
		}

		return newSalary;
	}

	public static char[] makeFirstChange(char[] salary) {

		int middlePoint = getMiddlePosition(salary);
		int leftPointer = middlePoint - 1;
		int rightPointer = middlePoint + 1;

		if (hasEvenNumberOfElements(salary.length)) {
			leftPointer = middlePoint-1;
			rightPointer = middlePoint;
		}

		int middleNumber = Character.getNumericValue(salary[middlePoint]);

		if (salary[leftPointer] < salary[rightPointer] && middleNumber < 9 && !hasEvenNumberOfElements(salary.length)) {
			System.out.println("Entró");
			middleNumber++;
			char middleChar = (char) (middleNumber + '0');
			System.out.println("middle"+middleChar);
			salary[middlePoint] = middleChar;

		}else{
			for (int i = 0; i < (salary.length-1)/2; i++) {
				if (salary[leftPointer] < salary[rightPointer]) {
					salary[leftPointer] = salary [rightPointer];
					break;
				}else if (salary[leftPointer] > salary[rightPointer]) {
					salary[rightPointer] = salary [leftPointer];
					break;
				}
				leftPointer--;
				rightPointer++;
			}
		}
		return salary;
	}

	public static char[] changeRightSide(char[] salary) {

		int leftSide = 0;
		int rightSide = salary.length-1;
		for (int i = 0; i < (salary.length-1)/2; i++) {
			salary[rightSide] = salary[leftSide];
			rightSide --;
			leftSide ++;
		}

		return salary;

	}

	public static char[] salaryToArray(String salary) {

		char[] salaryArray = salary.toCharArray();
		return salaryArray;
	}

	public static int getMiddlePosition(char[] salaryArray) {

		int salaryLength = salaryArray.length;
		int middlePoint = (salaryLength/2);

		if (hasEvenNumberOfElements(salaryLength)) {
			return middlePoint;
		}else {
			return middlePoint;
		}
	}

	public static boolean hasEvenNumberOfElements(int arrayLength) {
		return arrayLength % 2 == 0;
	}

}
