public aspect A6 {
        // you need to add variable declarations here for  for counting etc
		static int Expr.exprCount = 0;
		static int Assignment.assignCount = 0;
		int indentLevel = 0;
 
        //You need to add a few advices for print and evluate

        public String Expr.print(){
			String result = "";
			if(this.isPrimitive() && this.getValue() != null){
				return this.getValue().toString();
			}else if(this.isPrimitive() && this.getID() != null){
				result = this.getID();
			}else{
				String op = this.getOp();
				Expr left = this.getLeft();
				Expr right = this.getRight();
				result = "(" + left.print() + op + right.print() + ")";
			}
			return result;
		}

		public Integer Expr.evaluate(){
			Integer val = 0;
			if(this.isPrimitive() && this.getValue() != null){
				return this.getValue();
			}else if(this.isPrimitive() && this.getID() != null){
				val = Program.varTable.get(this.getID()).evaluate();
			}else{
				String op = this.getOp();
				Expr left = this.getLeft();
				Expr right = this.getRight();
				if(op.equals("+")){
					val = left.evaluate() + right.evaluate();
				}else if(op.equals("*")){
					val = left.evaluate() * right.evaluate();
				}else if(op.equals("-")){
					val = left.evaluate() - right.evaluate();
				}else if(op.equals("/")){
					val = left.evaluate() / right.evaluate();
				}
			}
			return val;
		}

	// Skip println statements
	void around() : call(*   *..print*(..)) && !within(A6) {
 		System.out.println("Number of Expressions: " + Expr.exprCount);
	}

	//count expr
	after(Expr e): execution( Expr.new(..)) && this(e) {
		e.exprCount = e.exprCount + 1;
	}

	// Print assignment statement before constructing it
	before(String var, Expr exp): call( Assignment.new(String, Expr))&& args(var, exp) {
		System.out.println("Assignment " + Assignment.assignCount + " is: " + var + " = " + exp.print() + ";");
		System.out.println(var + "==>" + exp.evaluate());

		Assignment.assignCount = Assignment.assignCount + 1;
	}

	before(): call(* *.evaluate()){
		indentLevel++;
		Expr exp = (Expr) thisJoinPoint.getTarget();
		for(int i = 0, sp = indentLevel * 3; i < sp; i++){
			System.out.print(" ");
		}
		System.out.println(exp.print() + "==> ?");
	}

	after(): call(* *.evaluate()){
		indentLevel--;
	}
}