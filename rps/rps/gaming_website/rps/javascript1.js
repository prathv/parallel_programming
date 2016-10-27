function validateForm(e)
{


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

}	
