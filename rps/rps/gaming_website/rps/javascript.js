window.onload()= function validateForm(e)
{
    var x=document.forms["myform"]["fname"].value;  
    if(x==null || x=="" )
    {
        alert("name can't be left blank");
			event.preventDefault();
	
        return false;
    }

    var y=document.forms["myform"]["lname"].value;
    if(y==null || y=="")
    {
        alert("last name is mandatory");
			event.preventDefault();

        return false;
    }




    var u=document.forms["myform"]["user"].value;
    if(u==null || u=="")
    {
        alert("User name is mandatory");
			event.preventDefault();

        return false;
    }


	var e = document.forms["myform"]["pass"].value;
	var d = document.forms["myform"]["pass2"].value;
	 if(e==null || e=="")
    {
        alert("password is mandatory");
					event.preventDefault();

        return false;
    }
	
	if(e != d){
			alert("passwords do not match");
			event.preventDefault();
			
	}

	
	var c = document.forms["myform"]["check"];
	alert(c);
	if (!c.checked)
	{
	
		alert("You need to accept terms of policy"):
			event.preventDefault();
	}
	
	return true;	

}
}
