

window.onload = function() {
	
	document.getElementById("rock").onclick = function() { myFunction(this.id)};
	document.getElementById("paper").onclick = function() { myFunction(this.id)};
	document.getElementById("scissor").onclick = function() { myFunction(this.id)};
	//document.getElementById("store").addEventListener("click",updateDb());	
	
	document.getElementById("resultimg").src = "user.png";
	document.getElementById("resultimgcomp").src = "evilcomp.png";
	var score = document.getElementById("score").innerHTML;
	var userscore = parseInt(score);	
	

	//function to calculate points
	function points(x){
	
		
	
	var value = document.getElementById("user").innerHTML ;
	var compvalue = document.getElementById("comp").innerHTML ;

		
	var store = document.getElementById('store').value;
	
	var userpoints = parseInt(value);
	var comppoints = parseInt(compvalue);
	
					if(x == "Draw")
					{
						return ;
					}
					
					if(x == "Win"){
						
						
						
						if (userpoints == 30) 
						{
							
						}
						
						else
						{
								userpoints += 10;
								string = userpoints.toString();
								
								document.getElementById("user").innerHTML = string;
						}
						
						userscore += 10;
						document.getElementById("score").innerHTML = userscore.toString();
						document.getElementById("store").value = userscore;						

			
						if (comppoints >= 10){
								comppoints -= 10;
								}
						else 
							{
								comppoints = 0;

							}
						document.getElementById("comp").innerHTML = comppoints.toString();
	
						
						
						
						
									
					}
					
					if(x == "Lose"){
						
		
								userpoints -= 10;						
								string = userpoints.toString();
								document.getElementById("user").innerHTML = string;
								
								if(userscore >= 10){
									userscore -= 10;
									
									}
									else
									{	
									userscore = 0;
									}
									
								document.getElementById("score").innerHTML = userscore.toString();				
								document.getElementById("store").value = userscore;						


						
		
						


					if (comppoints == 30) 
						{
							
						}
						
						else
						{
								comppoints += 10;
								string = comppoints.toString();
								
								document.getElementById("comp").innerHTML = string;
						}
						
					}
					
					if (comppoints == 0) 
						{
							
							
							var answer = confirm("You have beaten the comp, Want to play again, If you cancel the records are erased");
							var userwins = parseInt(document.getElementById("userwins").innerHTML);
							userwins += 1;
							
							var string = userwins.toString();
							document.getElementById("userwins").innerHTML = string;
							start(answer);
							
							
						}
						
					if (userpoints == 0) 
						{	
							var answer = confirm("You have been beaten by the comp, Want to play again. If you cancel, the existing records will be erased.");
							
							var compwins = parseInt(document.getElementById("compwins").innerHTML);
							compwins += 1;
							
							var string = compwins.toString();
							
							document.getElementById("compwins").innerHTML = string;
							
							start(answer);							
							
							
						}
						
	}
	
	//function to restart game
	
	function start(answer)
	{
			if(answer){
			document.getElementById("user").innerHTML = "30";
			document.getElementById("comp").innerHTML = "30";

			}
			
			else{
					window.location = "index.php";
			}
	}
	
	//function to determine game winner.
	function myFunction(x)
	{	
		var z = x;
		
		if(x == "rock")
		{
						document.getElementById("result").innerHTML = "You picked rock";
						document.getElementById("resultimg").src = "rock.jpg";
						var y = compFunc();
						result(y, "rock");
		}
		if(x == "paper")
		{
						document.getElementById("result").innerHTML = "You picked paper";
						document.getElementById("resultimg").src = "paper.jpg";
						var y = compFunc();
						result(y, "paper");
		}			
		if(x == "scissor")
		{
						document.getElementById("result").innerHTML = "You picked scissor";
						document.getElementById("resultimg").src = "scissor.jpg";
						var y = compFunc();
						result(y, "scissor");
		}
	}
	//function to return comp option
	function compFunc(){
		    var x = Math.floor((Math.random() * 3) + 1);
			
			if (x == 1)
			{
				document.getElementById("resultcomp").innerHTML = "Comp picked rock";
				document.getElementById("resultimgcomp").src = "rock.jpg";
				return "rock";
			}
			
			if (x == 2)
			{
				document.getElementById("resultcomp").innerHTML = "Comp picked paper";
				document.getElementById("resultimgcomp").src = "paper.jpg";
				return "paper";
			}
			
			if (x == 3)
			{
				document.getElementById("resultcomp").innerHTML = "Comp picked scissor";
				document.getElementById("resultimgcomp").src = "scissor.jpg";
				return "scissor";
			}

	}

	//function to display result.
	
	function result(y,x)
	{
			l = "Lose";
			w  = "Win";
			d = "Draw";
			
			if (y == "rock" && x == "rock")
			{
				document.getElementById("resultgame").innerHTML = "Draw";
				points(d);
			}
			
			if (y == "rock" && x == "scissor")
			{
				document.getElementById("resultgame").innerHTML = "You Lose";
								points(l);

			}
			
			if (y == "rock" && x == "paper")
			{
				document.getElementById("resultgame").innerHTML = "You Win";
								points(w);

			}
			
			
			if (y == "scissor" && x == "rock")
			{
				document.getElementById("resultgame").innerHTML = "You Win";
								points(w);

			}
			
			if (y == "paper" && x == "rock")
			{
				document.getElementById("resultgame").innerHTML = "You Lose";
								points(l);

			}
			
			if (y == "scissor" && x == "scissor")
			{
				document.getElementById("resultgame").innerHTML = "Draw";
								points(d);

			}
			
			if (y == "scissor" && x == "paper")
			{
				document.getElementById("resultgame").innerHTML = "You Lose";
								points(l);

			}
			
			
			if (y == "paper" && x == "scissor")
			{
				document.getElementById("resultgame").innerHTML = "You Win";
								points(w);

			}
			
				if (y == "paper" && x == "paper")
			{
				document.getElementById("resultgame").innerHTML = "Draw";
								points(d);

	}
			
		
						
	
	}




}

	function updateDb() {
  			var xhttp;
			var score = document.getElementById("store").value;
			score = parseInt(score);			
			var name = document.getElementById("name").value;
			name = name.toString();	
			//document.write(name);		
			
  			if (window.XMLHttpRequest) {
    		// code for modern browsers
         		xhttp = new XMLHttpRequest();
             		} else {
                 // code for IE6, IE5
                    	xhttp = new ActiveXObject("Microsoft.XMLHTTP");
                       }
                        xhttp.onreadystatechange = function() {
                        if (xhttp.readyState == 4 && xhttp.status == 200) {
         			document.write(xhttp.responseText); 
			alert("score has been sent");	

                             }
                                        };
                                xhttp.open("GET", "score.php?log="+name+"&store="+score, true);
                                xhttp.send();
                                  }	
			




